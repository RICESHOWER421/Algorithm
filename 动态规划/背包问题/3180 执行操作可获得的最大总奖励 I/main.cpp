#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        vector<vector<bool>> dp(n + 1, vector<bool>(4001));   //dp[i][j]表示选择前i个数字是否能获得j
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < rewardValues[i - 1]; j++) {
                dp[i][j] = dp[i - 1][j];
            }
            for (int j = rewardValues[i - 1]; j < 2 * rewardValues[i - 1]; j++) {
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - rewardValues[i - 1]]);
            }
        }

        for (int i = 4000; i >= 0; i--) {
            if (dp[n][i]) {
                return i;
            }
        }
    }
};

int main() {
    vector<int> nums = { 2,14,15,18 };
    cout << Solution().maxTotalReward(nums) << "\n";
	return 0;
}