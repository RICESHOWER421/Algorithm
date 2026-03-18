#include <bits/stdc++.h>
using namespace std;

//¶þÎ¬Ç°×ººÍ
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + grid[i - 1][j - 1];
                if (dp[i][j] <= k) ++ans;
                else break;
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}