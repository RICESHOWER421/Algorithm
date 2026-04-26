#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        queue<pair<int, int>> q;
        q.push({ 0,0 });

        //判断该格子可以走的方向
        auto check1 = [&](int pos, int way)->bool {
            if (pos == 1) return way == 2 || way == 3;
            else if (pos == 2) return way == 0 || way == 1;
            else if (pos == 3) return way == 1 || way == 2;
            else if (pos == 4) return way == 1 || way == 3;
            else if (pos == 5) return way == 0 || way == 2;
            else return way == 0 || way == 3;
        };

        //判断该方向是否可以到达目的格子
        auto check2 = [&](int way, int pos)->bool {
            if (way == 0) return pos == 2 || pos == 3 || pos == 4;
            else if (way == 1) return pos == 2 || pos == 5 || pos == 6;
            else if (way == 2) return pos == 1 || pos == 4 || pos == 6;
            else return pos == 1 || pos == 3 || pos == 5;
        };

        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            vis[tmp.first][tmp.second] = true;
            if (tmp.first == m - 1 && tmp.second == n - 1) return true;
            for (int i = 0; i < 4; i++) {
                int x = tmp.first + dx[i], y = tmp.second + dy[i];
                //首先判断该点有没有出边界或者访问过
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                    //然后判断这个位置你能走到的地方,最后判断你可以走的方向是否真的可以到达
                    if (check1(grid[tmp.first][tmp.second], i) && check2(i, grid[x][y])) {
                        q.push({ x,y });
                    }
                }
            }
        }
        return false;
    }
};

int main() {

	return 0;
}