#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp1(m + 1, vector<int>(n + 1));     //每行的前缀和
        vector<vector<int>> dp2 = dp1;  //每列的前缀和
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp1[i][j] = dp1[i][j - 1] + grid[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp2[j][i] = dp2[j - 1][i] + grid[j - 1][i - 1];
            }
        }

        for (int i = min(m, n); i > 1; i--) {
            for (int j = 1; j <= m - i + 1; j++) {
                for (int k = 1; k <= n - i + 1; k++) {
                    bool ok = true;
                    //判断每行是否相等
                    int tmp = dp1[j][k + i - 1] - dp1[j][k - 1];
                    for (int l = 1; l <= i - 1; l++) {
                        if (tmp != dp1[j + l][k + i - 1] - dp1[j + l][k - 1]) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) continue;

                    //判断每列是否相等
                    for (int l = 0; l <= i - 1; l++) {
                        if (tmp != dp2[j + i - 1][k + l] - dp2[j - 1][k + l]) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) continue;

                    //两个斜对角线总和计算
                    int s1 = 0, s2 = 0;
                    for (int l = 0; l <= i - 1; l++) {
                        s1 += grid[j + l - 1][k + l - 1];
                        s2 += grid[i + j - 2 - l][k + l - 1];
                    }
                    if (s1 != tmp || s2 != tmp) continue;
                    return i;
                }
            }
        }
        return 1;
    }
};

int main() {
    vector<vector<int>> grid = { {7,1,4,5,6}, {2,5,1,6,4}, {1,5,4,3,2}, {1,2,7,3,4} };
    cout << Solution().largestMagicSquare(grid) << "\n";

   	return 0;
}