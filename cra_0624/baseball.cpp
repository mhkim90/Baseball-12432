#include <iostream>
#include <vector>
#include <string>
using namespace std;

//class length_error : public exception {
//public:
//};

class Baseball {
public:
	void guess(const string& string) {
		if (string.size() != 3) {
			throw length_error("");
		}
	}
private:
};