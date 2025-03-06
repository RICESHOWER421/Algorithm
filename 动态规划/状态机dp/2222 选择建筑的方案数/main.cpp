#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    long long numberOfWays(string s) {
        int n = s.size();
        ll ans = 0;
        //0表示0的个数，1表示1的个数
        vector<vector<ll>> dp(n + 1, vector<ll>(2));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + (s[i - 1] == '0');
            dp[i][1] = dp[i - 1][1] + (s[i - 1] == '1');
        }

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1') {
                ans += (dp[i - 1][0] * (dp[n][0] - dp[i - 1][0]));
            }
            else {
                ans += (dp[i - 1][1] * (dp[n][1] - dp[i - 1][1]));
            }
        }

        return ans;
    }
};

int main() {

	return 0;
}