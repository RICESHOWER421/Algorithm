#include <iostream>
#include <string>
using namespace std;

void Test() {
	string s;
	cin >> s;

	s = 'R' + s + 'R';
	int mx = 0, index = 0;
	for (int i = 1; i < (int)s.size(); i++) {
		if (s[i] == 'R') {
			mx = max(mx, i - index);
			index = i;
		}
	}
	cout << mx << "\n";
}
int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}