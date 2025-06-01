#include <bits/stdc++.h>
using namespace std;

struct path {
	path(int x, int y, int energy, int trash) :_x(x), _y(y), _energy(energy), _trash(trash) {}
	int _x, _y, _energy, _trash;
};
int dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };
class Solution {
public:
	int minMoves(vector<string>& classroom, int energy) {
		int n = classroom.size(), m = classroom[0].size();
		vector<vector<int>> idx(n, vector<int>(m));
		int cnt = 0, r1 = 0, r2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (classroom[i][j] == 'L') {
					idx[i][j] = cnt++;
				}
				if (classroom[i][j] == 'S') {
					r1 = i;
					r2 = j;
				}
			}
		}

		int trash = 1 << cnt;
		vector<vector<vector<vector<int>>>> vis(n, vector<vector<vector<int>>>(m, vector<vector<int>>(energy + 1, vector<int>(trash))));
		queue<path> q;
		q.push(path(r1, r2, energy, trash - 1));
		int ans = 0;
		while (!q.empty()) {
			int sz = q.size();
			while (sz--) {
				auto tmp = q.front();
				q.pop();
				if (tmp._trash == 0) return ans;
				if (tmp._energy == 0) continue;
				for (int i = 0; i < 4; i++) {
					int x = tmp._x + dx[i], y = tmp._y + dy[i];
					if (x >= 0 && x < n && y >= 0 && y < m && classroom[x][y] != 'X') {
						int new_energy = (classroom[x][y] == 'R' ? energy : tmp._energy - 1);
						int new_trash = (classroom[x][y] == 'L' ? tmp._trash & ~(1 << idx[x][y]) : tmp._trash);
						if (!vis[x][y][new_energy][new_trash]) {
							vis[x][y][new_energy][new_trash] = true;
							q.push(path(x, y, new_energy, new_trash));
						}
					}
				}
			}
			++ans;
		}
		return -1;
	}
};
int main() {

	return 0;
}