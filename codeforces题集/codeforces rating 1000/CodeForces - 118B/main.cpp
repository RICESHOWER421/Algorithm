#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = { 1,-1,0,0 };
void Test() {
	int n = 0;
	cin >> n;
	vector<vector<int>> nums(2 * n + 1, vector<int>(2 * n + 1, -1));
	
	queue<pair<int, int>> q;
	q.push({n,n});
	int ret = n;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			pair<int, int> pos = q.front();
			q.pop();
			nums[pos.first][pos.second] = ret;
			for (int i = 0; i < 4; i++) {
				int x = pos.first + dx[i], y = pos.second + dy[i];
				if (x < 2 * n + 1 && x >= 0 && y < 2 * n + 1 && y >= 0 && nums[x][y] == -1 && ret >= 0) q.push({x,y});
			}
		}
		--ret;
	}

	for (int i = 0; i < 2 * n + 1; i++) {
		int index = 0;
		for (int j = 0; j < 2 * n + 1; j++) {
			if (nums[i][j] == -1 && !index) cout << " " << " ";
			else if (nums[i][j] != -1) {
				index = 1;
				cout << nums[i][j];
				if (j + 1 < 2 * n + 1 && nums[i][j + 1] != -1) cout << " ";
			}
			else break;
		}
		cout << "\n";
	}
}

int main() {
	Test();
	return 0;
}
