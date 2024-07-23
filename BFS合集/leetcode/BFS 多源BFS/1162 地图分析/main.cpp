#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = { 1,-1,0,0 };
int maxDistance(vector<vector<int>>& grid) {
	int n = grid.size();
	int ret = -1; //初值设置为-1是因为能够更好获得准确答案
	vector<vector<int>> nums(n, vector<int>(n, -1));

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 1) {
				nums[i][j] = 0;
				q.push({ i, j });
			}
		}
	}

	while (q.size()) {
		int size = q.size();
		if (size == n * n) return -1;
		while (size--) {
			pair<int, int> arr = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int x = arr.first + dx[i], y = arr.second + dy[i];
				if (x >= 0 && x < n && y >= 0 && y < n && nums[x][y] == -1) {
					nums[x][y] = nums[arr.first][arr.second] + 1;
					q.push({x, y});
				}
			}
		}
		++ret;
	}
	
	return ret;
}

int main() {
	vector<vector<int>> grid = { {0,0,0}, {0,0,0},{0,0,1} };
	cout << maxDistance(grid) << endl;
	return 0;
}