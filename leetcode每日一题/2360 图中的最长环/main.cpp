#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), ans = -1, ret = 0;
        vector<pair<bool, int>> vis(n);
        for (int i = 0; i < n; i++) {
            if (!vis[i].first) {
                ++ret;  //表示第几轮
                int cur = i, l = 0, r = 0;
                bool ok = false;
                while (edges[cur] != -1) {
                    if (vis[cur].first && vis[cur].second == ret) {   //如果到的点已经被访问过而且是在本轮被访问过，说明遇到回路
                        ok = true;
                        break;
                    }
                    else if (vis[cur].first && vis[cur].second != ret) {  //如果这个点是在之前访问过的，完全没有必要继续访问，直接结束循环
                        break;
                    }

                    vis[cur].first = true;
                    vis[cur].second = ret;
                    cur = edges[cur];
                    ++l;
                }

                if (ok) {
                    int tmp = cur;
                    cur = i;
                    while (cur != tmp) {
                        cur = edges[cur];
                        ++r;
                    }
                    ans = max(ans, l - r);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = { -1,4,-1,2,0,4 };
    cout << Solution().longestCycle(nums) << "\n";
    /*for (int i = 1; i < 1e5; i++) {
        cout << i << ",";
    }
    cout << 0 << "\n";*/
	return 0;
}