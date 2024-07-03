#include "pch.h"
#include "../cra_0624/baseball.cpp"
#include <vector>
#include <string>
using namespace std;

class BaseballFixture : public ::testing::Test {
public:
	Baseball game{ "123" };
	void assertTest(string numbers) {
		try {
			game.guess(numbers);
			FAIL();
		}
		catch (exception e) {

		}
	}
};

TEST_F(BaseballFixture, ExceptionTest) {
	assertTest("12");
	assertTest("12s");
	assertTest("121");
}

TEST_F(BaseballFixture, CorrectResultTest) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, TwoStrikeOneBallResultTest) {
	GuessResult result = game.guess("143");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}