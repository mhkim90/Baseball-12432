#include <iostream>
#include <vector>
#include <string>
using namespace std;

//class length_error : public exception {
//public:
//};

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	Baseball(const string& answer) : answer{ answer } {}

	GuessResult guess(const string& numbers) {
		checkNumbers(numbers);
		if (numbers == answer) {
			return { true, 3, 0 };
		}
		
		int strike = 0;
		int ball = 0;
		for (int i = 0; i < 3; i++) {
			if (answer[i] == numbers[i]) strike++;
			else {
				for (int j = 0; j < 3; j++) {
					if (i != j && answer[i] == numbers[j]) ball++;
				}
			}
		}
		return { false, strike, ball };
	}
private:
	string answer;

	bool isDuplicatedNumber(const string& numbers) {
		return (numbers[0] == numbers[1] ||
			numbers[1] == numbers[2] ||
			numbers[2] == numbers[0]);
	}

	void checkNumbers(const string& numbers) {
		if (numbers.size() != 3) {
			throw length_error("");
		}

		if (numbers.find_first_not_of("0123456789") != -1) {
			throw invalid_argument("");
		}

		if (isDuplicatedNumber(numbers)) {
			throw invalid_argument("");
		}
	}
};