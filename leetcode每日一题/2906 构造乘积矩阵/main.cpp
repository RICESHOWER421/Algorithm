#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    const int MOD = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        ll num = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = num;
                num = num * grid[i][j] % MOD;
            }
        }

        num = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                ans[i][j] = ans[i][j] * num % MOD;
                num = num * grid[i][j] % MOD;
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}