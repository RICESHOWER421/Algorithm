#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    //这个公式写的啥，完全没看懂
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        //dp[i]表示前i个数组被分割后的最大成本
        vector<ll> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + nums[i - 1];
            if (i >= 2) {
                dp[i] = max(dp[i], dp[i - 2] + nums[i - 2] - nums[i - 1]);
            }
        }
        return dp[n];
    }
};

int main() {

	return 0;
}