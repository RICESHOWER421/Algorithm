#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + (nums[i - 1] % modulo == k);
        }

        ll ans = 0;
        map<ll, int> cnts;
        for (auto& x : dp) {
            if (x >= k) {
                ans += cnts[(x - k) % modulo];
            }
            cnts[x % modulo]++;
        }
        return ans;
    }
};

int main() {

	return 0;
}