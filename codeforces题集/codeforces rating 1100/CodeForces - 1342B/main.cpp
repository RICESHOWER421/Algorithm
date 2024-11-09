#include <iostream>
#include <string>
using namespace std;

void Test() {
	string s;
	cin >> s;

	int ret_1 = 0, ret_2 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') ++ret_1;
		if (s[i] == '1') ++ret_2;
	}

	if (ret_1 == 0 || ret_2 == 0) {
		cout << s << "\n";
	}
	else {
		string ret;
		int index = 0;
		for (int i = 0; i < s.size(); i++) {
			if (index == 0) {
				if (s[i] == '1') ret += '0';
				else index = 1;
			}
			else {
				if (s[i] == '0') ret += '1';
				else index = 0;
			}
			ret += s[i];
		}
		if (ret.size() % 2) {
			ret += '1';
		}
		cout << ret << "\n";
	}
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}