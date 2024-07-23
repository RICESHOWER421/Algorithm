#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int ret = 0;
void bfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j) {
    queue<pair<int, int>>q;
    q.push({ i, j });
    vis[i][j] = true;

    int m = grid.size(), n = grid[0].size();
    if (i != 0 && i != m - 1 && j != 0 && j != n - 1) ++ret;

    while (q.size()) {
        pair<int, int>arr = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int x = arr.first + dx[k], y = arr.second + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y]) {
                q.push({x, y});
                vis[x][y] = true;
                if (i != 0 && i != m - 1 && j != 0 && j != n - 1) ++ret;
            }
        }
    }
}

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n));

    /*处理边界情况*/
    for (int i = 0; i < n; i++) {
        if (grid[0][i] == 1) bfs(grid, vis, 0, i);
        if (grid[m - 1][i] == 1) bfs(grid, vis, m - 1, i);
    }
    for (int i = 0; i < m; i++) {
        if (grid[i][0] == 1) bfs(grid, vis, i, 0);
        if (grid[i][n - 1] == 1)  bfs(grid, vis, i, n - 1);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j] && grid[i][j] == 1) bfs(grid, vis, i, j);
        }
    }

    return ret;
}

int main() {
    vector<vector<int>> grid = { {0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0} };
    cout << numEnclaves(grid) << endl;
	return 0;
}