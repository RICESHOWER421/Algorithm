#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> rets) {
        if (rets.empty()) {
            return 0;
        }
        int n = rets.size();
        vector<int> dp(n + 1);  //dp[i]表示偷取前i间房子所能获得的最大金额
        dp[1] = rets[0];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 2] + rets[i - 1], dp[i - 1]);
        }
        return dp.back();
    }

    int rob(vector<int>& nums) {
        vector<int> temp = nums.begin() + 2 < nums.end() - 1 ? vector<int>(nums.begin() + 2, nums.end() - 1) : vector<int>();
        return max(nums[0] + solve(temp), solve(vector<int>(nums.begin() + 1, nums.end())));
    }
};

int main() {    
    vector<int> nums = {2,3,2};
    cout << Solution().rob(nums) << "\n";
	return 0;
}