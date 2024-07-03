#include "pch.h"
#include "../cra_0624/baseball.cpp"
#include <vector>
using namespace std;

class BaseballFixture : public ::testing::Test {
public:
	Baseball baseball;
};

TEST_F(BaseballFixture, test) {
	EXPECT_EQ(1, 1);
}
