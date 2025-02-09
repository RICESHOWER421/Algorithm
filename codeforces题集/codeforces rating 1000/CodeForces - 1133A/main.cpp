#include <bits/stdc++.h>
using namespace std;

void Test() {
	string s1, s2;
	cin >> s1 >> s2;

	int ans1 = ((s1[0] - '0') * 10 + (s1[1] - '0')) * 60 + atoi(s1.substr(3).c_str()),
		ans2 = ((s2[0] - '0') * 10 + (s2[1] - '0')) * 60 + atoi(s2.substr(3).c_str());
	
	bool ok = false;
	if (ans1 > ans2) {
		ans2 += 1440;
		ok = true;
	}

	int ans = (ans1 + ans2) / 2 - (ok ? 1440 : 0);
	int n1 = ans / 60, n2 = ans % 60;
	if (n1 < 10) {
		cout << 0;
	}
	cout << n1 << ":";
	if (n2 < 10) {
		cout << 0;
	}
	cout << n2 << "\n";
}

int main() {
	Test();
	return 0;
}