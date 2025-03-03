#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.size() == 1) {
			if (s[0] >= '1' && s[0] <= '9') return 1;
			else return 0;
		}

		int num = (s[0] - '0') * 10 + s[1] - '0';
		if (s.size() == 2) {
			if (num > 10 && num <= 26 && num != 20) return 2;
			else {
				if (num == 10 || num == 20 || (s[0] != '0' && s[1] != '0')) return 1;
				else return 0;
			}
		}

		vector<int> dp(s.size());
		if (s[0] >= '1' && s[0] <= '9') dp[0] = 1;
		else dp[0] = 0;

		if (num > 10 && num <= 26 && num != 20) dp[1] = 2;
		else {
			if (num == 10 || num == 20 || (s[0] != '0' && s[1] != '0')) dp[1] = 1;
			else dp[1] = 0;
		}

		for (int i = 2; i < s.size(); i++) {
			if (s[i] >= '1' && s[i] <= '9') dp[i] += dp[i - 1];
			else dp[i] += 0;

			if ((s[i - 1] - '0') * 10 + s[i] - '0' >= 10 &&
				(s[i - 1] - '0') * 10 + s[i] - '0' <= 26) dp[i] += dp[i - 2];
			else dp[i] += 0;
		}

		return dp[s.size() - 1];
	}
};

int main() {

	return 0;
}