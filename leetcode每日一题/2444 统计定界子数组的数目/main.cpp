#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    const int MAX = 1e6 + 10;
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        nums.push_back(MAX);
        ll ans = 0, n = nums.size();
        int l = 0, r = 0, mn = MAX, mx = -1;
        queue<int> a, b;
        while (r < n) {
            mn = min(mn, nums[r]);
            mx = max(mx, nums[r]);
            if (nums[r] == minK) a.push(r);
            if (nums[r] == maxK) b.push(r);
            if (mn == minK && mx == maxK) {
                ++ans;
            }

            bool ok = false;
            if (mn < minK || mx > maxK) {
                while (true) {
                    if (nums[l] == minK && l == a.front()) a.pop();
                    if (nums[l] == maxK && l == b.front()) b.pop();
                    if (a.empty() || b.empty()) break;
                    ans += (r - max(a.front(), b.front()));
                    ++l;
                }
                ok = true;
            }

            ++r;
            if (ok) {
                mn = MAX, mx = -1;
                while (!a.empty()) a.pop();
                while (!b.empty()) b.pop();
                l = r;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = { 5,7,4,8,6,9,4,1,1,1,4,5,1,4,1,9,1,9,8,10 };
    cout << Solution().countSubarrays(nums, 1, 4) << "\n";
	return 0;
}