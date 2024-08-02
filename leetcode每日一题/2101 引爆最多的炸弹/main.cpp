#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int ret = 0;
void bfs(queue<pair<pair<int, int>, int>>& q , vector<bool>& vis, vector<vector<int>>& bombs) {
	int ans = 1;
	while (q.size()) {
		pair<pair<int, int>, int> arr = q.front();
		q.pop();
		for (int i = 0; i < bombs.size(); i++) {
			if (!vis[i] && pow(bombs[i][0] - arr.first.first, 2) + pow(bombs[i][1] - arr.first.second, 2) <= pow(arr.second, 2)) {
				vis[i] = true;
				q.push({{ bombs[i][0], bombs[i][1] }, bombs[i][2]});
				++ans;
			}
		}
	}
	ret = max(ans, ret);
}

int maximumDetonation(vector<vector<int>>& bombs) {
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < bombs.size(); i++) {
		vector<bool> vis(bombs.size());
		vis[i] = true;
		q.push({{ bombs[i][0], bombs[i][1] }, bombs[i][2]});
		bfs(q, vis, bombs);
	}

	return ret;
}

int main() {
	vector<vector<int>> bombs = { {1,2,3}, {2,3,1},{3,4,2},{4,5,3}, {5,6,4} };
	cout << maximumDetonation(bombs) << endl;
	return 0;
}