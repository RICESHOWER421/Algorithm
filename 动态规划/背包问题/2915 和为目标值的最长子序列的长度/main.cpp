#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));     //dp[i][j]表示在前i个数中选择，其值为j的最长子序列长度
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);    //不选第i个数
                //选择第i个数
                if (j - nums[i - 1] > 0) {
                    dp[i][j] = max(dp[i - 1][j - nums[i - 1]] ? dp[i - 1][j - nums[i - 1]] + 1 : 0, dp[i][j]);
                }
                else if(j - nums[i - 1] == 0) {
                    dp[i][j] = max(dp[i - 1][j], 1);
                }
            }
        }

        int mx = 0;
        for (int i = 1; i <= n; i++) {
            mx = max(mx, dp[i][target]);
        }
        return mx == 0 ? -1 : mx;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5};
    cout << Solution().lengthOfLongestSubsequence(nums, 9) << "\n";
	return 0;
}