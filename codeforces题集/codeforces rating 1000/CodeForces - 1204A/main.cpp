#include <iostream>
#include <string>
using namespace std;

void Test() {
	string s;
	cin >> s;

	int ok = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '1') {
			ok = 0;
			break;
		}
	}
	cout << (s.size() % 2 == 0 ? s.size() / 2 : s.size() / 2 + 1 - ok) << "\n";
}

int main() {
	Test();
	return 0;
}