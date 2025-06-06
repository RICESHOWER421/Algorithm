#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int) {
        if (edges.size() < n - 1) {
            return -1;
        }

        vector<vector<pair<int, int>>> g(n);
        int max_w = 0;
        for (auto& e : edges) {
            int x = e[0], y = e[1], w = e[2];
            g[y].emplace_back(x, w);
            max_w = max(max_w, w);
        }

        vector<int> vis(n);
        auto check = [&](int upper) -> bool {
            int left = n;
            auto dfs = [&](this auto&& dfs, int x) -> void {
                vis[x] = upper; // 避免每次二分重新创建 vis 数组
                left--;
                for (auto& [y, w] : g[x]) {
                    if (w <= upper && vis[y] != upper) {
                        dfs(y);
                    }
                }
            };
            dfs(0);
            return left == 0;
        };

        int left = 0, right = max_w + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            (check(mid) ? right : left) = mid;
        }
        return right > max_w ? -1 : right;
    }
};

//1 1 2 3 7 10
int main() {
    int n = 5, m = 4;
    vector<vector<int>> edges = { {4,3,77},{2,1,72},{3,1,39},{3,4,88},{0,2,51},{3,2,7},{1,3,38},{4,2,3} };
    cout << Solution().minMaxWeight(n, edges, m) << "\n";
    return 0;
}