#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
        _n = n;
        g = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
        for (auto& x : edges) {
            g[x[0]].push_back({ x[1], x[2] });
        }
    }

    void addEdge(vector<int> edge) {
        g[edge[0]].push_back({ edge[1], edge[2] });
    }

    int shortestPath(int node1, int node2) {
        vector<int> dist(_n, -1);
        dist[node1] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, node1 });
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
        return dist[node2];
    }

    vector<vector<pair<int, int>>> g;
    int _n;
};

int main() {
    vector<vector<int>> edges = { {0,2,5},{0,1,2},{1,2,1},{3,0,3} };
    Graph g(4, edges);
    g.shortestPath(3,2);
    return 0;
}