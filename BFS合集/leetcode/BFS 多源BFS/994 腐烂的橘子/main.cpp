#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int orangesRotting(vector<vector<int>>& grid) {
	int m = grid.size(), n = grid[0].size();
	int time = -1, sum = 0; //sum表示好的橘子的个数

	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 2) q.push({ i, j });
			if (grid[i][j] == 1) ++sum;
		}
	}
	
	if (sum == 0) return 0;
	while (q.size()) {
		int sz = q.size();
		++time;
		while (sz--) {
			pair<int, int> arr = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int x = arr.first + dx[i], y = arr.second + dy[i];
				if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
					q.push({x,y});
					grid[x][y] = 2;
					--sum;
				}
			}
		}
	}

	if (sum) return -1;
	else return time;
}

int main() {
	vector<vector<int>> grid = { {2,1,1}, {0,1,1}, {1,0,1} };
	cout << orangesRotting(grid) << endl;
	return 0;
}