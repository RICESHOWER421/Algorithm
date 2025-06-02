#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int ret = 0;

int bfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j) {
    queue<pair<int, int>> q;
    q.push({ i, j });
    int count = 0;

    while (q.size()) {
        pair<int, int> arr = q.front();
        q.pop();
        if (!vis[arr.first][arr.second]) {
            vis[arr.first][arr.second] = true;
            ++count;
        }

        for (int k = 0; k < 4; k++) {
            int x = arr.first + dx[k], y = arr.second + dy[k];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1 && !vis[x][y]) {
                q.push({ x, y });
                vis[x][y] = true;
                ++count;
            }
        }
    }
    return count;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !vis[i][j])
                ret = max(bfs(grid, vis, i, j), ret);
        }
    }
    return ret;
}

int main() {

	return 0;
}