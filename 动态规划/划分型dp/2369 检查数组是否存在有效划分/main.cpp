#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        //dp[i]表示前i个数字是否可以有效划分
        vector<bool> dp(n + 1);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            if (i >= 2 && nums[i - 1] == nums[i - 2] && dp[i - 2] ||
                i >= 3 && nums[i - 1] == nums[i - 2] && nums[i - 1] == nums[i - 3] && dp[i - 3] ||
                i >= 3 && nums[i - 1] == nums[i - 2] + 1 && nums[i - 1] == nums[i - 3] + 2 && dp[i - 3]) {
                dp[i] = true;
            }
        }
        return dp[n];
    }
};

int main() {

	return 0;
}