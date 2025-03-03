#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        vector<string> ans;
        for (int i = 1; i <= pow(2, 15); i *= 5) {
            int ret = i;
            string tmp;
            while (ret) {
                tmp += (ret % 2 + '0');
                ret /= 2;
            }
            reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
        }

        int n = s.size();
        //dp[i]表示前i个子字符串的最小分割
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int mn = 0x3f3f3f3f;
            for (auto& x : ans) {
                int m = x.size();
                if (i >= m && s.substr(i - m, m) == x) {
                    mn = min(mn, dp[i - m] + 1);
                }
            }
            dp[i] = mn;
        }
        return dp[n] == 0x3f3f3f3f ? -1 : dp[n];
    }
};

int main() {

	return 0;
}