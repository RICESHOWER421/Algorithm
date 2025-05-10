#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
	using ll = long long;
	const ll MOD = 1e9 + 7;
	int countRestrictedPaths(int n, vector<vector<int>>& edges) {
		vector<int> dist(n + 1, -1);
		dist[n] = 0;
		vector<vector<pair<int, int>>> g(n + 1);
		for (auto& x : edges) {
			g[x[0]].push_back({ x[1], x[2] });
			g[x[1]].push_back({ x[0], x[2] });
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0, n });
		while (!pq.empty()) {
			auto tmp = pq.top();
			pq.pop();

			int len = tmp.first, dst = tmp.second;
			if (len > dist[dst]) continue;
			for (auto& x : g[dst]) {
				int new_len = len + x.second;
				if (dist[x.first] == -1 || new_len < dist[x.first]) {
					dist[x.first] = new_len;
					pq.push({ new_len, x.first });
				}
			}
		}

		vector<ll> dp(n + 1);	//dp[i]表示从1-i的受限路径个数
		dp[1] = 1;
		vector<int> idx;
		for (int i = 1; i <= n; i++) {
			idx.push_back(i);
		}
		sort(idx.begin(), idx.end(), [&](const int a, const int b) {
			return dist[a] > dist[b];
			});
		for (int i = 0; i < n; i++) {
			int pos = idx[i];
			for (auto& x : g[pos]) {
				if (dist[x.first] < dist[pos]) dp[x.first] = (dp[x.first] + dp[pos]) % MOD;
			}
		}
		return dp[n];
	}
};

int main() {

	return 0;
}