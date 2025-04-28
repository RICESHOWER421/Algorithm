#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    long long countSubarrays(vector<int>& nums, long long k) {
        ll ans = 0, sum = 0, l = 0, r = 0, n = nums.size();
        ll pre = 0;    //pre¼ÇÂ¼Ç°×ººÍ
        while (r < n) {
            pre += (ll)nums[r];
            sum = pre * (r - l + 1);
            while (sum >= k) {
                ans += (n - r);
                pre -= (ll)nums[l++];
                sum = pre * (r - l + 1);
                // cout << ans << "\n";
            }
            ++r;
        }
        return n * (n + 1) / 2 - ans;
    }
};

int main() {

	return 0;
}