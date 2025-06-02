#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n));
        auto bfs = [&](int x, int y, int pos)->void {
            queue<pair<int, int>> q;
            q.push({ x,y });
            grid[x][y] = pos;
            while (!q.empty()) {
                auto tmp = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int x1 = tmp.first + dx[i], y1 = tmp.second + dy[i];
                    if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && !vis[x1][y1] && grid[x1][y1]) {
                        vis[x1][y1] = true;
                        grid[x1][y1] = pos;
                        q.push({ x1, y1 });
                    }
                }
            }
        };

        bool ok = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j]) {
                    if (!ok) {
                        bfs(i, j, 1);
                        ok = true;
                    }
                    else {
                        bfs(i, j, 2);
                    }
                }
            }
        }

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vis[i][j] = false;
                if (grid[i][j] == 1) {
                    q.push({ i, j });
                    vis[i][j] = true;
                }
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto tmp = q.front();
                q.pop();
                if (grid[tmp.first][tmp.second] == 2) return cnt - 1;
                for (int i = 0; i < 4; i++) {
                    int x1 = tmp.first + dx[i], y1 = tmp.second + dy[i];
                    if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && !vis[x1][y1]) {
                        vis[x1][y1] = true;
                        q.push({ x1, y1 });
                    }
                }
            }
            ++cnt;
        }
        return -1;
    }
};
int main() {
    vector<vector<int>> grid = { {0,1,0},{0,0,0},{0,0,1} };
    cout << Solution().shortestBridge(grid) << "\n";
	return 0;
}