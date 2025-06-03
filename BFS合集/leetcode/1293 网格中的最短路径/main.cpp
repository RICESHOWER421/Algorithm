#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
	int shortestPath(vector<vector<int>>& grid, int k) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(k + 1)));
		queue<vector<int>> q;
		q.push({ 0,0,k });
		int cnt = 0;
		while (!q.empty()) {
			int sz = q.size();
			while (sz--) {
				auto tmp = q.front();
				q.pop();
				if (tmp[0] == m - 1 && tmp[1] == n - 1) return cnt;
				for (int i = 0; i < 4; i++) {
					int x = tmp[0] + dx[i], y = tmp[1] + dy[i];
					if (x >= 0 && x < m && y >= 0 && y < n) {
						if (grid[x][y]) {
							if (tmp[2] && !vis[x][y][tmp[2] - 1]) {
								vis[x][y][tmp[2] - 1] = true;
								q.push({ x, y, tmp[2] - 1 });
							}
						}
						else {
							if (!vis[x][y][tmp[2]]) {
								vis[x][y][tmp[2]] = true;
								q.push({ x, y, tmp[2] });
							}
						}
					}
				}
			}
			++cnt;
		}
		return -1;
	}
};

int main() {
	vector<vector<int>> grid = { {0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0} };
	cout << Solution().shortestPath(grid, 1) << "\n";
	return 0;
}