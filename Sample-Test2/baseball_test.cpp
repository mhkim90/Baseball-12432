#include "pch.h"
#include "../cra_0624/baseball.cpp"
#include <vector>
#include <string>
using namespace std;

class BaseballFixture : public ::testing::Test {
public:
	Baseball game;
};

TEST_F(BaseballFixture, test) {
	EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST_F(BaseballFixture, test2) {
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}
