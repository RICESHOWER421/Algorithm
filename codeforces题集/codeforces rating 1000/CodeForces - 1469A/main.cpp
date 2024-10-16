#include <iostream>
#include <string>
using namespace std;

//注意这里只有一个(和一个)
void Test() {
	string s;
	cin >> s;

	if (s[0] == ')' || s.back() == '(') {
		cout << "NO" << endl;
		return;
	}

	int ret = 0;
	for (auto& x : s) {
		if (x == '?') ++ret;
	}

	if (ret % 2 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}