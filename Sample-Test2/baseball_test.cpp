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

	void resultTest(string numbers, GuessResult expected) {
		GuessResult result = game.guess(numbers);

		EXPECT_EQ(expected.solved, result.solved);
		EXPECT_EQ(expected.strikes, result.strikes);
		EXPECT_EQ(expected.balls, result.balls);
	}
};

TEST_F(BaseballFixture, ExceptionTest) {
	assertTest("12");
	assertTest("12s");
	assertTest("121");
}

TEST_F(BaseballFixture, CorrectResultTest) {
	resultTest("123", { true, 3, 0 });
}

TEST_F(BaseballFixture, TwoStrikeOneBallResultTest) {
	resultTest("143", { false, 2, 0 });
}

TEST_F(BaseballFixture, OneStrikeTwoBallResultTest) {
	resultTest("132", { false, 1, 2 });
}