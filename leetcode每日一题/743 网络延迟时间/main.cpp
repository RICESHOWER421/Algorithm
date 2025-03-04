#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

//朴素写法（适用于稠密图）
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2)); // 邻接矩阵
        for (auto& t : times) {
            g[t[0] - 1][t[1] - 1] = t[2];
        }

        vector<int> dis(n, INT_MAX / 2), done(n);
        dis[k - 1] = 0;
        while (true) {
            int x = -1;
            for (int i = 0; i < n; i++) {
                if (!done[i] && (x < 0 || dis[i] < dis[x])) {
                    x = i;
                }
            }
            if (x < 0) {
                int mx = -1;
                for (auto& x : dis) {
                    mx = max(x, mx);
                }
                return mx;
            }
            if (dis[x] == INT_MAX / 2) { // 有节点无法到达
                return -1;
            }
            done[x] = true; // 最短路长度已确定（无法变得更小）
            for (int y = 0; y < n; y++) {
                // 更新 x 的邻居的最短路
                dis[y] = min(dis[y], dis[x] + g[x][y]);
            }
        }
    }
};

//堆写法（适用于稀疏图）
//class Solution {
//public:
//    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//        vector<vector<pair<int, int>>> g(n); // 邻接表
//        for (auto& t : times) {
//            g[t[0] - 1].emplace_back(t[1] - 1, t[2]);
//        }
//
//        vector<int> dis(n, INT_MAX);
//        dis[k - 1] = 0;
//        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
//        pq.emplace(0, k - 1);
//        while (!pq.empty()) {
//            auto [dx, x] = pq.top();
//            pq.pop();
//            if (dx > dis[x]) { // x 之前出堆过
//                continue;
//            }
//            for (auto& [y, d] : g[x]) {
//                int new_dis = dx + d;
//                if (new_dis < dis[y]) {
//                    dis[y] = new_dis; // 更新 x 的邻居的最短路
//                    pq.emplace(new_dis, y);
//                }
//            }
//        }
//        int mx = ranges::max(dis);
//        return mx < INT_MAX ? mx : -1;
//    }
//};
int main() {
    vector<vector<int>> times = { {2,3,3},{2,1,1},{1,3,1} };
    int n = 3, k = 2;
    cout << Solution().networkDelayTime(times, n, k) << "\n";
	return 0;
}