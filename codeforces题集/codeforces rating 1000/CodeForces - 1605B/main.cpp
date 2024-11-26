#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	string s;
	cin >> s;

	bool ok = true;
	int ret = 0, count = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			if (ret) ok = false;
		}
		else {
			if (ret == 0) ret = 1;
			++count;
		}
	}

	if (ok) cout << 0 << "\n";
	else {
		cout << 1 << "\n";
		vector<int> ans;
		for (int i = n - 1; i >= n - count; i--) {
			if (s[i] != '1') {
				ans.push_back(i + 1);
			}
		}

		for (int i = n - count - 1; i >= 0; i--) {
			if (s[i] == '1') {
				ans.push_back(i + 1);
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans.size() << " ";
		for (auto& x : ans) {
			cout << x << " ";
		}
		cout << "\n";
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