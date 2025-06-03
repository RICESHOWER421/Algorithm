#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
	vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
		int n = grid.size(), m = grid[0].size();
		vector<vector<int>> vis(n, vector<int>(m, -1));
		vector<vector<int>> ret;
		queue<pair<int, int>> q;
		q.push({ start[0], start[1] });
		vis[start[0]][start[1]] = 0;
		if (grid[start[0]][start[1]] >= pricing[0] && grid[start[0]][start[1]] <= pricing[1]) ret.push_back({ start[0], start[1] });

		int cnt = 1;
		while (!q.empty()) {
			int sz = q.size();
			while (sz--) {
				auto tmp = q.front();
				q.pop();
				for (int i = 0; i < 4; i++) {
					int x = tmp.first + dx[i], y = tmp.second + dy[i];
					if (x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == -1 && grid[x][y]) {
						vis[x][y] = cnt;
						q.push({ x, y });
						if (grid[x][y] >= pricing[0] && grid[x][y] <= pricing[1]) {
							ret.push_back({ x, y });
						}
					}
				}
			}
			++cnt;
		}

		// for(int i = 0; i < n; i++){
		//     for(int j = 0; j < m; j++){
		//         cout << vis[i][j] << " ";
		//     }
		//     cout << "\n";
		// }

		sort(ret.begin(), ret.end(), [&](const vector<int>& a, const vector<int>& b) {
			if (vis[a[0]][a[1]] != vis[b[0]][b[1]]) return vis[a[0]][a[1]] < vis[b[0]][b[1]];
			else {
				if (grid[a[0]][a[1]] != grid[b[0]][b[1]]) return grid[a[0]][a[1]] < grid[b[0]][b[1]];
				else {
					if (a[0] != b[0]) return a[0] < b[0];
					else return a[1] < b[1];
				}
			}
			});

		vector<vector<int>> ans;
		for (int i = 0; i < min(k, (int)ret.size()); i++) {
			ans.push_back(ret[i]);
		}
		return ans;
	}
};

int main() {

	return 0;
}