#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
void bfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j) {
	int m = grid.size(), n = grid[0].size();
	queue<pair<int, int>> q;
	q.push({i, j});
	vis[i][j] = true;

	while (q.size()) {
		pair<int, int> arr = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int x = arr.first + dx[k], y = arr.second + dy[k];
			if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] == '1') {
				q.push({x,y});
				vis[x][y] = true;
			}
		}
	}
}

int numIslands(vector<vector<char>>& grid) {
	int m = grid.size(), n = grid[0].size();
	int ret = 0;
	vector<vector<bool>> vis(m, vector<bool>(n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (!vis[i][j] && grid[i][j] == '1')
				bfs(grid, vis, i, j), ret++;
	return ret;
}

int main() {
	vector<vector<char>> grid = { {'1','1','1','1','0'},
								  {'1','1','0','1','0'},
								  {'1','1','0','0','0'},
								  {'0','0','0','0','0'}, };
	cout << numIslands(grid) << endl;
	return 0;
}