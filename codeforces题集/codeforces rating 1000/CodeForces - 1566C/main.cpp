#include <iostream>
#include <string>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s1[i] != s2[i]) ans += 2;
		else {
			if (s1[i] == '0') {
				if (i + 1 < n && s1[i + 1] == s2[i + 1] && s1[i + 1] == '1') {
					ans += 2;
					++i;
				}
				else ans++;
			}
			else {
				if (i + 1 < n && s1[i + 1] == s2[i + 1] && s1[i + 1] == '0') {
					ans += 2;
					++i;
				}
			}
		}
	}
	cout << ans << "\n";
}
int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}