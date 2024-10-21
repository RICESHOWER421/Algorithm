#include <iostream>
#include <string>
using namespace std;

void Test() {
	string s;
	cin >> s;
	s[0] = s[0] == '9' ? s[0] : ('9' - (s[0] - '0') < s[0] ? '9' - (s[0] - '0') : s[0]);
	for (int i = 1; i < s.size(); i++) {
		if ('9' - (s[i] - '0') < s[i]) s[i] = '9' - (s[i] - '0');
	}
	cout << s << "\n";
}

int main() {
	Test();
	return 0;
}