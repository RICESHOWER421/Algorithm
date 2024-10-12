#include <iostream>
#include <string>
using namespace std;

void Test() {
	string s;
	cin >> s;

	int index = 0;
	for (int i = 1; i < (int)s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			index = 1;
			break;
		}
	}

	if (!index) {
		for (auto& x : s) {
			if (x >= 'a' && x <= 'z') x -= ' ';
			else x += ' ';
		}
	}
	cout << s << endl;
}

int main() {
	Test();
	return 0;
}