#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;
    int numberOfWays(int n, int x) {
        int cur = 1;
        while (pow(cur, x) < n) { ++cur; }
        vector<vector<ll>> dp(cur + 1, vector<ll>(n + 1));    //dp[i][j]表示选取前i个数时，其值为j的个数
        for (int i = 0; i <= cur; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= cur; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j - pow(i, x) >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - pow(i, x)]) % MOD;
                }
            }
        }
        return dp[cur][n];
    }
};

int main() {
    cout << Solution().numberOfWays(4,1) << "\n";
	return 0;
}