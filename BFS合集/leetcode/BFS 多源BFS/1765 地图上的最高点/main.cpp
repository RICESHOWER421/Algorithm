#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = { 1,-1,0,0 };
vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
	int m = isWater.size(), n = isWater[0].size();

	//return_nums两个作用
	//return_nums[i][j] == -1 这个位置的元素并没用被遍历过
	//return_nums[i][j] != -1 这个位置的元素的高度
	vector<vector<int>> return_nums(m, vector<int>(n, -1));

	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (isWater[i][j] == 1){
				return_nums[i][j] = 0;
				q.push({i, j});
			}
		}
	}

	while (q.size()) {
		pair<int, int> arr = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = arr.first + dx[i], y = arr.second + dy[i];
			if (x >= 0 && x < m && y >= 0 && y < n && return_nums[x][y] == -1) {
				return_nums[x][y] = return_nums[arr.first][arr.second] + 1;
				q.push({x,y});
			}
		}
	}
	return return_nums;
}

int main() {
	vector<vector<int>> isWater = { {0,0,1},{1,0,0},{0,0,0} };
	vector<vector<int>> return_nums = highestPeak(isWater);
	for (int i = 0; i < return_nums.size(); i++) {
		for (int j = 0; j < return_nums[0].size(); j++) {
			cout << return_nums[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}