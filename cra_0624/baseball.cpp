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
		throw length_error("");
	}
private:
};