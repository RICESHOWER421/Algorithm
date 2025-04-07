#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (sum % 2) return false;

        int m = nums.size();
        sum /= 2;
        //dp[i][j]表示选取nums中前i个数，总和是否为j
        vector<vector<int>> dp(m + 1, vector<int>(sum + 1));
        for (int i = 0; i <= m; i++) dp[i][0] = true;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j - nums[i - 1] >= 0) dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                else dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[m][sum];
    }
};

int main() {
	
	return 0;
}