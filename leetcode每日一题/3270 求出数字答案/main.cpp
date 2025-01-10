#include <iostream>
#include <string>
using namespace std;

int generateKey(int num1, int num2, int num3) {
	string s1 = to_string(num1), s2 = to_string(num2), s3 = to_string(num3);
	if (s1.size() != 4) {
		while (s1.size() != 4) s1 = '0' + s1;
	}
	if (s2.size() != 4) {
		while (s2.size() != 4) s2 = '0' + s2;
	}
	if (s3.size() != 4) {
		while (s3.size() != 4) s3 = '0' + s3;
	}
	
	string ret;
	for (int i = 0; i < 4; i++) {
		ret += (min(s1[i], min(s2[i], s3[i])));
	}
	return atoi(ret.c_str());
}

int main() {
	
	return 0;
}