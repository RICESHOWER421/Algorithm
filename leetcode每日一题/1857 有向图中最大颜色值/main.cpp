#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

class Solution {
public:
	int largestPathValue(string colors, vector<vector<int>>& edges) {
		int n = colors.size();
		vector<vector<int>> g(n);
		for (auto& x : edges) {
			if (x[0] == x[1]) return -1;
			g[x[0]].push_back(x[1]);
		}

		vector<vector<int>> mem(n);
		auto dfs = [&](auto&& dfs, int pos)->vector<int> {
			if (!mem[pos].empty()) return mem[pos];

			mem[pos] = { 0 };
			vector<int> cnts(26);
			for (auto& x : g[pos]) {
				vector<int> tmp = dfs(dfs, x);
				if (tmp.size() == 1) return tmp;
				for (int i = 0; i < 26; i++) cnts[i] = max(cnts[i], tmp[i]);
			}
			cnts[colors[pos] - 'a']++;
			mem[pos] = cnts;
			return cnts;
		};

		int ans = 0;
		for (int i = 0; i < n; i++) {
			vector<int> tmp = dfs(dfs, i);
			if (tmp.size() == 1) return -1;
			for (auto& x : tmp) {
				ans = max(ans, x);
			}
		}
		return ans;
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	return 0;
}