#include <iostream>
#include <vector>
#include <string>
using namespace std;

//class length_error : public exception {
//public:
//};

class Baseball {
public:
	void guess(const string& numbers) {
		if (numbers.size() != 3) {
			throw length_error("");
		}

		if (numbers.find_first_not_of("0123456789") != -1) {
			throw invalid_argument("");
		}

		if (numbers[0] == numbers[1] ||
			numbers[1] == numbers[2] ||
			numbers[2] == numbers[0]) {
			throw invalid_argument("");
			}
	}
private:
};