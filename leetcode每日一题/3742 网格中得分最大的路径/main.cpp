#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), ans = -1;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));  //dp[i][j][k]表示到达(i,j)点时，总花费为k时获得的最大分数
        dp[0][0][0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int mx = -1;
                for (int l = 0; l <= k; l++) {
                    if (grid[i][j] > 0) {     //大于0的单元格需要一点花费
                        if (i - 1 >= 0 && l && dp[i - 1][j][l - 1] != -1) mx = max(mx, dp[i - 1][j][l - 1]);
                        if (j - 1 >= 0 && l && dp[i][j - 1][l - 1] != -1) mx = max(mx, dp[i][j - 1][l - 1]);
                    }
                    else {
                        if (i - 1 >= 0 && dp[i - 1][j][l] != -1) mx = max(mx, dp[i - 1][j][l]);
                        if (j - 1 >= 0 && dp[i][j - 1][l] != -1) mx = max(mx, dp[i][j - 1][l]);
                    }
                    if (mx != -1) dp[i][j][l] = mx + grid[i][j];     //mx等于-1，说明该状态不可能获取
                    if (i == m - 1 && j == n - 1) {
                        ans = max(ans, dp[i][j][k]);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}