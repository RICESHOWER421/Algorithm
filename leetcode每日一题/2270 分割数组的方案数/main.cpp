#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<ll> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }

        int ans = 0;
        for (int i = 1; i <= n - 1; i++) {
            if (dp[i] >= dp[n] - dp[i]) {
                ++ans;
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}