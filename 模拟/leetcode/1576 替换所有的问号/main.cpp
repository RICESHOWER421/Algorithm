#include <iostream>
#include <string>
using namespace std;

string modifyString(string s) {
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			for (char ch = 'a'; ch <= 'z'; ch++) {
				if ((i == 0 || s[i - 1] != ch) && (i == n - 1 || s[i + 1] != ch)) {
					s[i] = ch;
					break;
				}
			}
		}
	}
	return s;
}

int main() {
	string s = "???????";
	cout << modifyString(s) << endl;
	return 0;
}