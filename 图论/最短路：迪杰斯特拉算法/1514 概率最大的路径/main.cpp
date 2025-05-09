#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
		vector<vector<pair<int, double>>> g(n);
		vector<double> dist(n, 0);
		dist[start_node] = 1;
		for (int i = 0; i < edges.size(); i++) {
			g[edges[i][0]].push_back({ edges[i][1], succProb[i] });
			g[edges[i][1]].push_back({ edges[i][0], succProb[i] });
		}

		priority_queue<pair<double, int>> pq;
		pq.push({ 1, start_node });
		while (!pq.empty()) {
			auto tmp = pq.top();
			pq.pop();

			double ret = tmp.first, dst = tmp.second;
			if (ret < dist[dst]) continue;
			for (auto& x : g[dst]) {
				double new_ret = ret * x.second;
				if (new_ret > dist[x.first]) {
					// cout << x.first << " " << dist[x.first] << "\n";
					dist[x.first] = new_ret;
					pq.push({ new_ret, x.first });
				}
			}
		}
		return dist[end_node];
	}
};

int main() {
	vector<vector<int>> edges = { {0,2,5},{0,1,2},{1,2,1},{3,0,3} };
	Graph g(4, edges);
	g.shortestPath(3, 2);
	return 0;
}