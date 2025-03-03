#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        //dp[i]表示前i个字符分割后剩下的最小字符数
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            int mn = 0x3f3f3f3f;
            for (auto& x : dictionary) {
                int m = x.size();
                if (i >= m && s.substr(i - m, m) == x) {
                    mn = min(dp[i - m], mn);
                }
                else {
                    mn = min(dp[i - 1] + 1, mn);
                }
            }
            dp[i] = mn;
        }
        return dp[n];
    }
};

int main() {

	return 0;
}