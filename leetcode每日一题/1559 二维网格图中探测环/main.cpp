#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));

        auto check = [&](int i, int j)->bool {
            if (i == 1 && j == 2 || i == 2 && j == 1 || i == 3 && j == 4 || i == 4 && j == 3) return false;
            return true;
        };
        //st:0表示任意方向 1表示上 2表示下 3表示左 4表示右
        auto dfs = [&](auto&& dfs, int x, int y, char a, int st)->bool {
            vis[x][y] = true;
            bool ok = false;
            for (int i = 0; i < 4; i++) {
                int n_x = x + dx[i], n_y = y + dy[i];
                if (n_x >= 0 && n_x < n && n_y >= 0 && n_y < m && check(st, i + 1) && grid[n_x][n_y] == a) {
                    if (vis[n_x][n_y]) return true;
                    else ok = dfs(dfs, n_x, n_y, a, i + 1);
                }
            }
            return ok;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && dfs(dfs, i, j, grid[i][j], 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> grid = { {'a','b','b'}, {'b','z','b'}, {'b','b','a'}};
    cout << Solution().containsCycle(grid) << "\n";
	return 0;
}