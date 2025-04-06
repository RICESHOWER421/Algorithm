#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int return_num = INT_MIN;
        vector<int> dp(n + 1);

        for (int i = 1; i <= n; i++) {
            dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
            return_num = max(dp[i], return_num);
        }

        return return_num;
    }
};

int main() {

	return 0;
}