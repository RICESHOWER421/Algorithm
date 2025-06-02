#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
	int m = mat.size(), n = mat[0].size();
	vector<vector<int>> return_nums(m, vector<int>(n, -1));

	queue<pair<int, int>> q;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				q.push({ i, j });
				return_nums[i][j] = 0;
			}
		}
	}

	while (q.size()) {
		pair<int, int>arr = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int x = arr.first + dx[k], y = arr.second + dy[k];
			if (x >= 0 && x < m && y >= 0 && y < n && return_nums[x][y] == -1) {
				q.push({ x,y });
				return_nums[x][y] = return_nums[arr.first][arr.second] + 1;
			}
		}
	}

	return return_nums;
}

int main() {
	vector<vector<int>> nums = { {0,0,0}, {0,1,0}, {0,0,0} };
	vector<vector<int>> return_nums = updateMatrix(nums);
	for (int i = 0; i < return_nums.size(); i++) {
		for (int j = 0; j < return_nums[0].size(); j++) {
			cout << return_nums[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}