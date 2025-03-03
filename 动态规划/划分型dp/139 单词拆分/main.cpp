#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        //dp[i]表示前n个字符是否可以拆分
        vector<int> dp(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (auto& x : wordDict) {
                int m = x.size();
                if (i >= m && s.substr(i - m, m) == x && dp[i - m]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {

	return 0;
}