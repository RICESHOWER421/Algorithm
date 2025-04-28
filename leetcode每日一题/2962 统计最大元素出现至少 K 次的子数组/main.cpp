#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0, mx = 0;
        for (auto& x : nums) {
            mx = max(x, mx);
        }

        ll ans = 0, cnt = 0;
        while (r < n) {
            cnt += nums[r++] == mx;
            while (cnt == k) {
                cnt -= nums[l++] == mx;
            }
            ans += l;
        }
        return ans;
    }
};
int main() {

	return 0;
}