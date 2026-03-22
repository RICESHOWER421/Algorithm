#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, { LLONG_MIN, LLONG_MAX }));    //dp[i][j][k]表示到点(i,j)所能得到的最大(k == 0)和最小(k == 1)值 (特注：不要去区分正负数，不然很容易把自己绕进去)
        dp[0][0][0] = dp[0][0][1] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    dp[i][j][0] = max(dp[i][j][0], max(dp[i - 1][j][0] * grid[i][j], dp[i - 1][j][1] * grid[i][j]));
                    dp[i][j][1] = min(dp[i][j][1], min(dp[i - 1][j][0] * grid[i][j], dp[i - 1][j][1] * grid[i][j]));
                }
                if (j > 0) {
                    dp[i][j][0] = max(dp[i][j][0], max(dp[i][j - 1][0] * grid[i][j], dp[i][j - 1][1] * grid[i][j]));
                    dp[i][j][1] = min(dp[i][j][1], min(dp[i][j - 1][0] * grid[i][j], dp[i][j - 1][1] * grid[i][j]));
                }
            }
        }
        //特别注意，由于负数太大取模很可能会获得一个正数，可能会影响答案，所以只能在最后取模
        return dp[m - 1][n - 1][0] < 0 ? -1 : dp[m - 1][n - 1][0] % MOD;
    }
};

int main() {

	return 0;
}