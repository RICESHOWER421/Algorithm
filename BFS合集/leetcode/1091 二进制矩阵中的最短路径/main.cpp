#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[8] = { -1,0,1,-1,1,-1,0,1 }, dy[8] = { -1,-1,-1,0,0,1,1,1 };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]) return -1;
        int n = grid.size();
        queue<pair<int, int>> q;
        q.push({ 0,0 });
        int cnt = 0;
        vector<vector<bool>> vis(n, vector<bool>(n));
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto tmp = q.front();
                q.pop();
                if (tmp.first == n - 1 && tmp.second == n - 1) return cnt + 1;
                for (int i = 0; i < 8; i++) {
                    int x = tmp.first + dx[i], y = tmp.second + dy[i];
                    if (x >= 0 && x < n && y >= 0 && y < n && !grid[x][y] && !vis[x][y]) {
                        q.push({ x, y });
                        vis[x][y] = true;
                    }
                }
            }
            ++cnt;
        }
        return -1;
    }
};

int main() {

    return 0;
}