#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, { 0,0 }));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j][0] = dp[i - 1][j][0] + dp[i][j - 1][0] - dp[i - 1][j - 1][0] + (grid[i - 1][j - 1] == 'X');
                dp[i][j][1] = dp[i - 1][j][1] + dp[i][j - 1][1] - dp[i - 1][j - 1][1] + (grid[i - 1][j - 1] == 'Y');
                if (dp[i][j][0] && dp[i][j][0] == dp[i][j][1]) ++ans;
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}