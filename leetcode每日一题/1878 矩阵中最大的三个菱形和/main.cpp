#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int, greater<int>> s;
        vector<int> ans;
        auto check = [&](int x, int y, int cnt)->bool {
            bool ok = true;
            int y1 = y, y2 = y, ori = x, sum = grid[x][y];
            while (x < ori + 2 * cnt) {
                int n_x = x + 1, n_y1 = y1 + (ok ? 1 : -1), n_y2 = y2 - (ok ? 1 : -1);
                if (n_x < m && n_y1 >= 0 && n_y1 < n && n_y1 >= 0 && n_y2 >= 0 && n_y2 < n) {
                    sum += grid[n_x][n_y1] + grid[n_x][n_y2];
                    x = n_x, y1 = n_y1, y2 = n_y2;
                    if (x == ori + cnt) ok = false;
                }
                else return false;
            }
            sum -= grid[x][y1];
            s.insert(sum);
            return true;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                s.insert(grid[i][j]);
                int cur = 1;
                while (check(i, j, cur)) ++cur;
            }
        }

        for (auto& x : s) {
            if (ans.size() < 3) ans.push_back(x);
            else break;
        }
        return ans;
    }
};

int main() {

	return 0;
}