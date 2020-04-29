#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "Player.h"
using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

struct PlayerTest : public testing::Test
{
	Player *p;

	virtual void SetUp()
	{
		p = new Player("Player1");
	}
	
	virtual void TearDown()
	{
		delete p;
	}
};

TEST_F(PlayerTest, GetNameTest)
{
	EXPECT_STREQ("Player1",p->getName().c_str());
}

TEST_F(PlayerTest, MarkerTest)
{
	p->setMarker('X');
	EXPECT_EQ('X',p->getMarker());

	p->setMarker('O');
	EXPECT_EQ('O',p->getMarker());

	p->setMarker('A');
	EXPECT_NE('A',p->getMarker());
}

TEST_F(PlayerTest, placeMarker)
{
	
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
