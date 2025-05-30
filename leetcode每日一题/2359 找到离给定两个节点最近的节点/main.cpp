#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> g(n);
        for (int i = 0; i < n; i++) {
            g[i] = edges[i];
        }

        vector<vector<bool>> visit(2, vector<bool>(n));
        vector<int> cnts(n);
        auto bfs = [&](int node, int op)->void {
            vector<bool> vis(n);
            queue<int> q;
            q.push(node);
            int ret = 0;
            while (!q.empty()) {
                int sz = q.size();
                while (sz--) {
                    int pos = q.front();
                    q.pop();
                    visit[op][pos] = true;
                    cnts[pos] = (!op ? ret : max(cnts[pos], ret));
                    ++ret;
                    if (g[pos] != -1 && !visit[op][g[pos]]) q.push(g[pos]);
                }
            }
        };

        bfs(node1, 0);
        bfs(node2, 1);
        int ans = 1e5 + 10, ans_pos = 0;
        for (int i = 0; i < n; i++) {
            if (visit[0][i] && visit[1][i] && cnts[i] < ans) {
                ans = cnts[i];
                ans_pos = i;
            }
        }
        return ans_pos;
    }
};

int main() {

	return 0;
}