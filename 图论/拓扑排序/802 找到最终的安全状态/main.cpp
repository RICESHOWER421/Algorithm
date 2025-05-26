#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> g(n);
        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            for (auto& x : graph[i]) {
                ret[i]++;
                g[x].push_back(i);
            }
        }

        vector<bool> vis(n);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!ret[i]) {
                // cout << i << " ";
                q.push(i);
                vis[i] = true;
            }
        }

        while (!q.empty()) {
            int pos = q.front();
            q.pop();

            for (auto& x : g[pos]) {
                ret[x]--;
                if (!ret[x]) {
                    q.push(x);
                    vis[x] = true;
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}