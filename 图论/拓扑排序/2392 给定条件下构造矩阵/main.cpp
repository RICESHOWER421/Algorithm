#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
	vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
		auto toposort = [&](vector<vector<int>>& nums)->vector<int> {
			vector<vector<bool>> vis(k + 1, vector<bool>(k + 1));
			vector<vector<int>> pts(k + 1, vector<int>());
			vector<int> cnts(k + 1);
			vector<bool> check(k + 1);

			for (auto& x : nums) {
				if (!vis[x[0]][x[1]]) {
					pts[x[0]].push_back(x[1]);
					cnts[x[1]]++;
					check[x[0]] = check[x[1]] = true;
				}
				vis[x[0]][x[1]] = true;
			}

			queue<int> q;
			for (int i = 1; i <= k; i++) {
				if (!cnts[i]) q.push(i);
			}

			vector<int> ans;
			while (!q.empty()) {
				int pos = q.front();
				q.pop();
				ans.push_back(pos);
				for (auto& x : pts[pos]) {
					cnts[x]--;
					if (!cnts[x]) {
						q.push(x);
					}
				}
			}

			for (int i = 1; i <= k; i++) {
				if (!check[i]) {
					ans.push_back(i);
				}
			}
			return ans;
		};

		auto n1 = toposort(rowConditions), n2 = toposort(colConditions);
		if (n1.size() < k || n2.size() < k) return {};
		vector<vector<int>> ans(k, vector<int>(k));
		for (int i = 0; i < k; i++) {
			int num = n1[i];
			for (int j = 0; j < k; j++) {
				if (n2[j] == num) {
					ans[i][j] = num;
					break;
				}
			}
		}
		return ans;
	}
};

int main() {

	return 0;
}