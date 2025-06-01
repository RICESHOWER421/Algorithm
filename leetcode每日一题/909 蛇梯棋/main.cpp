#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int snakesAndLadders(vector<vector<int>>& board) {
		int n = board.size();
		queue<int> q;
		q.push(1);
		int cnt = 0;
		vector<bool> vis(n * n + 1);
		while (!q.empty()) {
			int sz = q.size();
			while (sz--) {
				int pos = q.front();
				q.pop();
				if (pos == n * n) return cnt;
				for (int i = pos + 1; i <= min(pos + 6, n * n); i++) {
					int x = (i - 1) / n, y = (i - 1) % n;
					if (x % 2) {
						y = n - y - 1;
					}
					int ret = board[n - x - 1][y];
					if (ret == -1) {
						ret = i;
					}
					if (!vis[ret]) {
						vis[ret] = true;
						q.push(ret);
					}
				}
			}
			++cnt;
		}
		return -1;
	}
};

int main() {

	return 0;
}