#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "Player.h"
#include "utility.h"
using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::ElementsAre;
using ::testing::InvokeWithoutArgs;

struct PlayerTest : public testing::Test
{
	Player *p;
	utility* util= new utility();

	virtual void SetUp()
	{
		p = new Player("Player1",util);
	}
	
	virtual void TearDown()
	{
		delete p;
		delete util;
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

class MockUtility : public utility
{
	public:
		MOCK_METHOD0(getStringInput, string());
};

TEST(PlayerTest1, placeMarker)
{
	MockUtility util;
	Player* p = new Player("Player1",&util);

	string s ="1,2";
	EXPECT_CALL(util, getStringInput())
	.Times(1)
	.WillOnce(Return("1,2"));

	vector<int> output;
	output.push_back(1);
	output.push_back(2);

	bool result  = p->placeMarker(output);

	EXPECT_EQ(result, true);
	EXPECT_THAT(output , ElementsAre(1,2));
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	::testing::InitGoogleMock(&argc, argv); 
	return RUN_ALL_TESTS();
}
