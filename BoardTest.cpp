#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Board.h"
using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

struct BoardTest : public testing::Test
{
	Board *b;

	virtual void SetUp()
	{
		b = new Board();
	}
	
	virtual void TearDown()
	{
		delete b;
	}
};

TEST_F(BoardTest, isBoardFinishedTest)
{
	vector<int> vec(2);

	vec.push_back(0);
	vec.push_back(0);
	b->updateBoard(vec,'X');

	vec.clear();
	vec.push_back(0);
	vec.push_back(1);
	b->updateBoard(vec,'O');

	vec.clear();
	vec.push_back(0);
	vec.push_back(2);
	b->updateBoard(vec,'X');
	
	vec.clear();
	vec.push_back(1);
	vec.push_back(0);
	b->updateBoard(vec,'X');
	
	vec.clear();
	vec.push_back(1);
	vec.push_back(1);
	b->updateBoard(vec,'O');
	
	vec.clear();
	vec.push_back(1);
	vec.push_back(2);
	b->updateBoard(vec,'O');
	
	vec.clear();
	vec.push_back(2);
	vec.push_back(0);
	b->updateBoard(vec,'O');
	
	vec.clear();
	vec.push_back(2);
	vec.push_back(1);
	b->updateBoard(vec,'X');
	
	vec.clear();
	vec.push_back(2);
	vec.push_back(2);
	b->updateBoard(vec,'O');

	EXPECT_EQ(true,b->isBoardFinished());
}

TEST_F(BoardTest, isBoardWonTest)
{
	vector<int> vec(2);

	vec.push_back(0);
	vec.push_back(0);
	b->updateBoard(vec,'O');

	vec.clear();
	vec.push_back(1);
	vec.push_back(1);
	b->updateBoard(vec,'O');

	vec.clear();
	vec.push_back(2);
	vec.push_back(2);
	b->updateBoard(vec,'O');

	EXPECT_EQ(true,b->isBoardWon());
}

TEST_F(BoardTest, updateBoardTest)
{
	vector<int> vec(2);
	vec.push_back(0);
	vec.push_back(0);
	EXPECT_EQ(true, b->updateBoard(vec,'O'));
	EXPECT_EQ(false, b->updateBoard(vec,'O'));
	EXPECT_EQ(false, b->updateBoard(vec,'X'));

	vec.clear();
	vec.push_back(0);
	vec.push_back(1);
	EXPECT_EQ(true, b->updateBoard(vec,'O'));
	EXPECT_EQ(false, b->updateBoard(vec,'O'));
	EXPECT_EQ(false, b->updateBoard(vec,'X'));
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
