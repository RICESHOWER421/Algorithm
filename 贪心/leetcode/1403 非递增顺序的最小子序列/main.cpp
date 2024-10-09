#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        int n = nums.size();
        vector<int> ans;
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }

        for (int i = 1; i <= n; i++) {
            ans.push_back(nums[i - 1]);
            if (dp[i] > dp.back() - dp[i]) break;
        }
        return ans;
    }
};

int main() {
    
	return 0;
}