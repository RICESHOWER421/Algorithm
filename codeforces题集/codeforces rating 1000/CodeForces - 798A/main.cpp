#include <iostream>
#include <string>
using namespace std;

void Test() {
	string s;
	cin >> s;
		
	int n = s.size();
	int ret = 0, cur = 0;
	while (cur < n / 2) {
		if (s[cur] != s[n - 1 - cur]) ++ret;
		++cur;
	}

	if (n % 2 && ret <= 1 || n % 2 == 0 && ret == 1) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}
}

int main() {
	Test();
	return 0;
}