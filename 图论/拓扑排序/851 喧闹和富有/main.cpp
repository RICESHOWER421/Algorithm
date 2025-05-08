#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
		int n = quiet.size();
		vector<vector<bool>> vis(n, vector<bool>(n));
		vector<vector<int>> pts(n, vector<int>());
		vector<int> cnts(n);	//表示入度点个数 

		for (auto& x : richer) {
			cnts[x[0]]++;
			pts[x[1]].push_back(x[0]);
		}

		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (!cnts[i]) q.push(i);
		}

		while (!q.empty()) {
			int pos = q.front();
			q.pop();

			for (auto& x : pts[pos]) {
				cnts[x]--;
				vis[pos][x] = true;
				for (int i = 0; i < n; i++) {
					vis[i][x] = vis[i][pos] || vis[i][x];
				}
				if (!cnts[x]) {
					q.push(x);
				}
			}
		}

		vector<int> ans;
		for (int i = 0; i < n; i++) {
			int mn = quiet[i], p = i;
			for (int j = 0; j < n; j++) {
				if (vis[i][j]) {
					if (quiet[j] < mn) {
						mn = quiet[j];
						p = j;
					}
				}
			}
			ans.push_back(p);
		}
		return ans;
	}
};

int main() {

	return 0;
}