#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MN = -1e9;
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(3, MN)));  //dp[i][j][k]表示在(i,j)点已经使用k次感化所获得的最大金币数
        for (int i = 0; i <= 2; i++) {
            dp[0][1][i] = dp[1][0][i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 0; k <= 2; k++) {
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]) + coins[i - 1][j - 1];    //在此格不使用感化
                    if (coins[i - 1][j - 1] < 0 && k) {//如果是负数，可以考虑在这一格使用感化
                        dp[i][j][k] = max(dp[i][j][k], max(dp[i - 1][j][k - 1], dp[i][j - 1][k - 1]));
                    }
                }
                //cout << dp[i][j][0] << " " << dp[i][j][1] << " " << dp[i][j][2] << "\n";
            }
        }
        return max({ dp[m][n][0], dp[m][n][1], dp[m][n][2] });
    }
};

int main() {

	return 0;
}