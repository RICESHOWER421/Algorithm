#include <iostream>
#include <string>
using namespace std;

//0101010001110111
void Test() {
	string s;
	cin >> s;

	int ret = 0, index = -1;
	for(int i = 0; i < s.size(); i++){
		if (s[i] == '1') {
			++ret;
		}
		else {
			if (ret >= 2) {
				index = i;
				break;
			}
			else {
				ret = 0;
			}
		}
	}

	if (index == -1) {
		cout << "YES" << "\n";
	}
	else {
		ret = 0;
		for (int i = index; i < s.size(); i++) {
			if (s[i] == '0') {
				++ret;
				if (ret >= 2) {
					cout << "NO" << "\n";
					return;
				}
			}
			else {
				ret = 0;
			}
		}
		cout << "YES" << "\n";
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