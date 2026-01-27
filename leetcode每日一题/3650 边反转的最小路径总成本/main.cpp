#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> g(n);        //first是目标点，second是路径权值
        for (auto& x : edges) {
            g[x[0]].push_back({ x[1], x[2] });
            g[x[1]].push_back({ x[0], 2 * x[2]});
        }

        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[0] = 0;
        pq.push({0,0});     //first是距离权值，second是目标点
        while (!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();
            if (tmp.first > dist[tmp.second]) continue;     //到目标点已经存在更优的选择，直接略过
            if (tmp.second == n - 1) return tmp.first;
            for (auto& x : g[tmp.second]) {
                int new_dist = tmp.first + x.second;
                if (new_dist < dist[x.first]) {
                    dist[x.first] = new_dist;
                    pq.push({ new_dist, x.first });
                }
            }
        }
        return -1;  //不存在到达路径
    }
};

int main() {

	return 0;
}