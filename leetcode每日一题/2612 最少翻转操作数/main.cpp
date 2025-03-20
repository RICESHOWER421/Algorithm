#include <bits/stdc++.h>
using namespace std;

//1 2 3 4 5 6 7 8 9
//
class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> nums(n);
        for (auto& x : banned) {
            nums[x] = -1;
        }
        nums[p] = 0;

        set<int> st[2];
        for (int i = 0; i < n; i++) {
            if (i != p && nums[i] != -1) {
                st[i % 2].insert(i);
            }
        }
        st[0].insert(n);    
        st[1].insert(n);

        int ret = 1;
        queue<int> q;
        q.push(p);
        while (!q.empty()) {
            int pos = q.front();
            q.pop();
            int l = max(pos - k + 1, k - pos - 1), r = min(pos + k - 1, 2 * n - k - pos - 1);
            auto& status = st[l % 2];
            for (auto it = status.lower_bound(l); *it <= r; it = status.erase(it)) {
                nums[*it] = nums[pos] + 1;
                q.push(*it);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0 && i != p) {
                nums[i] = -1;
            }
        }
        return nums;
    }
};

int main() {

	return 0;
}