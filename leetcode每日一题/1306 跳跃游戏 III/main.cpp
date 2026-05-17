#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n);
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int pos = q.front();
                q.pop();
                vis[pos] = true;
                if (!arr[pos]) return true;
                int r = pos + arr[pos];
                if (r < n && !vis[r]) q.push(r);
                int l = pos - arr[pos];
                if (l >= 0 && !vis[l]) q.push(l);
            }
        }
        return false;
    }
};

int main() {

	return 0;
}