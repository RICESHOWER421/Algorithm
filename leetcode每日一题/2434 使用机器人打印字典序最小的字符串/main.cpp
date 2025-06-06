#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class Solution {
public:
	string robotWithString(string s) {
		int n = s.size();
		vector<char> rets(n);
		rets[n - 1] = s.back();
		for (int i = n - 2; i >= 0; i--) {
			rets[i] = min(s[i], rets[i + 1]);
		}

		string tmp, ans;
		for (int i = 0; i < n; i++) {
			tmp += s[i];
			while (!tmp.empty() && i + 1 < n && tmp.back() <= rets[i + 1]) {
				ans += tmp.back();
				tmp.pop_back();
			}
		}

		for (int i = tmp.size() - 1; i >= 0; i--) {
			ans += tmp[i];
		}
		return ans;
	}
};

int main() {
	string s = "bac";
	cout << Solution().robotWithString(s) << "\n";
	return 0;
}

//a....a....a...a..cccbc....