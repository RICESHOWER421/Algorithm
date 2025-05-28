#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> a(n), b(m);
        for (auto& x : edges1) {
            a[x[0]].push_back(x[1]);
            a[x[1]].push_back(x[0]);
        }
        for (auto& x : edges2) {
            b[x[0]].push_back(x[1]);
            b[x[1]].push_back(x[0]);
        }

        int c1 = 0, c2 = 0, d1 = 0, d2 = 0;
        vector<int> g(n);
        vector<bool> v1(n), v2(m);
        auto dfs = [&](auto&& dfs, int pos, int cnt, int op)->void {
            if (!op) v1[pos] = true;
            else v2[pos] = true;

            if (!op) g[pos] = cnt % 2;

            if (cnt % 2) {
                if (!op) ++c2;
                else ++d2;
            }
            else {
                if (!op) ++c1;
                else ++d1;
            }

            for (auto& x : (!op ? a[pos] : b[pos])) {
                if (!op ? !v1[x] : !v2[x]) dfs(dfs, x, cnt + 1, op);
            }
        };

        dfs(dfs, 0, 0, 0);
        dfs(dfs, 0, 0, 1);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = g[i] % 2 ? c2 : c1;
            ans[i] += max(d1, d2);
        }
        return ans;
    }
};

int main() {

	return 0;
}