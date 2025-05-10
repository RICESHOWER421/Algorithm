#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
	vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
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
				if (dist[x.first] == -1 || new_len < dist[x.first]) {
					dist[x.first] = new_len;
					pq.push({ new_len, x.first });
				}
			}
		}

		map<pair<int, int>, bool> hash_map;
		vector<bool> ans(edges.size()), vis(n);
		if (dist[n - 1] == -1) return ans;
		queue<int> q;
		q.push(n - 1);
		vis[n - 1] = true;
		while (!q.empty()) {
			int pos = q.front();
			q.pop();

			for (auto& x : g[pos]) {
				if (dist[pos] - x.second == dist[x.first]) {
					hash_map[{pos, x.first}] = hash_map[{x.first, pos}] = true;
					if (!vis[x.first]) {
						vis[x.first] = true;
						q.push(x.first);
					}
				}
			}
		}

		for (int i = 0; i < edges.size(); i++) {
			if (hash_map.count({ edges[i][0], edges[i][1] }) || hash_map.count({ edges[i][1], edges[i][0] })) {
				ans[i] = true;
			}
		}
		return ans;
	}
};

int main() {
	vector<vector<int>> edges = { {0,2,5},{0,1,2},{1,2,1},{3,0,3} };
	Graph g(4, edges);
	g.shortestPath(3, 2);
	return 0;
}