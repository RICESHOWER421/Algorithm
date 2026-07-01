#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        if (grid[0][0]) return 0;
        int n = grid.size();
        int l = 0, r = n * n;
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(n, 0x3f3f3f3f));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q.push({ i,j });
                    dist[i][j] = 0;
                }
            }
        }

        int cnt = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto tmp = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int x = tmp.first + dx[i], y = tmp.second + dy[i];
                    if (x >= 0 && x < n && y >= 0 && y < n && dist[x][y] == 0x3f3f3f3f) {
                        dist[x][y] = cnt;
                        q.push({ x,y });
                    }
                }
            }
            ++cnt;
        }

        auto check = [&](int pos)->bool {
            vector<vector<bool>> vis(n, vector<bool>(n));
            queue<pair<int, int>> q;
            q.push({ 0,0 });
            vis[0][0] = true;
            if (dist[0][0] < pos) return false;
            while (!q.empty()) {
                auto tmp = q.front();
                q.pop();
                if (tmp.first == n - 1 && tmp.second == n - 1) return true;
                for (int i = 0; i < 4; i++) {
                    int x = tmp.first + dx[i], y = tmp.second + dy[i];
                    if (x >= 0 && x < n && y >= 0 && y < n && dist[x][y] >= pos && !vis[x][y]) {
                        vis[x][y] = true;
                        q.push({ x,y });
                    }
                }
            }
            return false;
        };

        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};

int main() {
    vector<vector<int>> grid = { {0,1,1},{0,0,0},{0,0,0} };
    cout << Solution().maximumSafenessFactor(grid) << "\n";
	return 0;
}