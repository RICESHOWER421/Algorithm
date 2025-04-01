#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);  //dp[i]表示抢劫前i家所获得的最大金额
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
        }
        return dp.back();
    }
};

int main() {

	return 0;
}