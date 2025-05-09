#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
	vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
		vector<int> dist(n, -1);
		dist[0] = 0;
		vector<vector<pair<int, int>>> g(n);
		for (auto& x : edges) {
			g[x[0]].push_back({ x[1], x[2] });
			g[x[1]].push_back({ x[0], x[2] });
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0,0 });
		while (!pq.empty()) {
			auto tmp = pq.top();
			pq.pop();

			int len = tmp.first, dst = tmp.second;
			if (len > dist[dst]) continue;
			for (auto& x : g[dst]) {
				int new_len = len + x.second;
				if (new_len < disappear[x.first] && ((dist[x.first] == -1) || (new_len < dist[x.first]))) {
					dist[x.first] = new_len;
					pq.push({ new_len, x.first });
				}
			}
		}
		return dist;
	}
};

int main() {

	return 0;
}