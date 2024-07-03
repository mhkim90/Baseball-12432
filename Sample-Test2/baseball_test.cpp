#include "pch.h"
#include "../cra_0624/baseball.cpp"
#include <vector>
#include <string>
using namespace std;

class BaseballFixture : public ::testing::Test {
public:
	Baseball game;
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