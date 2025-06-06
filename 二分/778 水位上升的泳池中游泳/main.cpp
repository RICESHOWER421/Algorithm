#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool vis[51][51];
class Solution {
public:
	int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
	int swimInWater(vector<vector<int>>& grid) {
		int n = grid.size(), l = 0, r = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				r = max(r, grid[i][j]);
			}
		}

		auto check = [&](int mid)->bool {
			if (grid[0][0] > mid) return false;
			memset(vis, false, sizeof(vis));
			queue<pair<int, int>> q;
			q.push({ 0,0 });
			while (!q.empty()) {
				auto tmp = q.front();
				q.pop();
				if (tmp.first == n - 1 && tmp.second == n - 1) return true;
				for (int i = 0; i < 4; i++) {
					int x = tmp.first + dx[i], y = tmp.second + dy[i];
					if (x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && grid[x][y] <= mid) {
						vis[x][y] = true;
						q.push({ x,y });
					}
				}
			}
			return false;
		};

		while (l < r) {
			int mid = l + (r - l) / 2;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		return l;
	}
};

int main() {
	return 0;
}

//a....a....a...a..cccbc....