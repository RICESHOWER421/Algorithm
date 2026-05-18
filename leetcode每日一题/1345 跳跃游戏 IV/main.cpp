#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> idx;
        vector<int> vis(n, -1);
        vis[0] = 0;
        for (int i = 0; i < n; i++) {
            idx[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int pos = q.front();
                q.pop();
                if (pos == n - 1) return vis[pos];
                if (pos - 1 >= 0 && vis[pos - 1] == -1) {
                    q.push(pos - 1);
                    vis[pos - 1] = vis[pos] + 1;
                }
                if (pos + 1 < n && vis[pos + 1] == -1) {
                    q.push(pos + 1);
                    vis[pos + 1] = vis[pos] + 1;
                }

                if (idx.find(arr[pos]) != idx.end()) {
                    for (auto& x : idx[arr[pos]]) {
                        if (x != pos && vis[x] == -1) {
                            q.push(x);
                            vis[x] = vis[pos] + 1;
                        }
                    }
                    idx.erase(arr[pos]);
                }
            }
        }
        return -1;
    }
};

int main() {

	return 0;
}