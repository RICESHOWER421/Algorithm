#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        for (int i = min(m,n); i >= 1; i--) {
            for (int j = 1; j <= n - i + 1; j++) {
                for (int k = 1; k <= m - i + 1; k++) {
                    if (dp[j + i - 1][k + i - 1] - dp[j + i - 1][k - 1] - dp[j - 1][k + i - 1] + dp[j - 1][k - 1] <= threshold) return i;
                }
            }
        }
        return 0;
    }
};

int main() {

	return 0;
}