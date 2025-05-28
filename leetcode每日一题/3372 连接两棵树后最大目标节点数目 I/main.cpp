#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
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

        int mx = -1;
        auto bfs = [&](int pos, int op)->int {
            vector<int> vis(max(n, m));
            int ret = 0, tmp = op;
            queue<int> q;
            q.push(pos);

            ++tmp;
            while (tmp--) {
                int sz = q.size();
                ret += sz;
                while (sz--) {
                    int p = q.front();
                    q.pop();
                    vis[p] = true;
                    for (auto& x : (op == k ? a[p] : b[p])) {
                        if (!vis[x]) q.push(x);
                    }
                }
            }
            return ret;
        };

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = bfs(i, k);
        }
        for (int i = 0; i < m; i++) {
            mx = max(mx, bfs(i, k - 1));
        }
        for (int i = 0; i < n; i++) {
            ans[i] += mx;
        }
        return ans;
    }
};

int main() {

    return 0;
}