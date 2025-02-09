#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ans(n, vector<int>(n));
		vector<vector<bool>> vis(n, vector<bool>(n));

		int ret = 0;
		int index = 0;
		int i = 0, j = 0;
		while (ret != n * n) {
			if (index == 0) {
				while (!vis[i][j]) {
					vis[i][j] = true;
					++ret;
					ans[i][j] = ret;
					if (j == n - 1 || vis[i][j + 1]) break;
					++j;
				}
				++i;
			}
			else if (index == 1) {
				while (!vis[i][j]) {
					vis[i][j] = true;
					++ret;
					ans[i][j] = ret;
					if (i == n - 1 || vis[i + 1][j]) break;
					++i;
				}
				--j;
			}
			else if (index == 2) {
				while (!vis[i][j]) {
					vis[i][j] = true;
					++ret;
					ans[i][j] = ret;
					if (j == 0 || vis[i][j - 1]) break;
					--j;
				}
				--i;
			}
			else {
				while (!vis[i][j]) {
					vis[i][j] = true;
					++ret;
					ans[i][j] = ret;
					if (i == 0 || vis[i - 1][j]) break;
					--i;
				}
				++j;
			}
			index = (index + 1) % 4;
		}
		return ans;
	}
};

int main() {

	return 0;
}