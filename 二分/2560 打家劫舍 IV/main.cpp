#include <bits/stdc++.h>
using namespace std;

//二分 + dp
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = 1, r = 0, n = nums.size();
        for (auto& x : nums) {
            r = max(x, r);
        }

        auto check = [&](int mid)->bool {
            vector<int> dp(n + 1);	//dp[i]表示前i个房屋中小于mid值的房子个数 
            dp[1] = nums[0] <= mid ? 1 : 0;
            for (int i = 2; i <= n; i++) {
                dp[i] = dp[i - 1];
                if (nums[i - 1] <= mid) {
                    dp[i] = max(dp[i], dp[i - 2] + 1);
                }
            }
            return dp.back() >= k;
        };

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

int main() {
    vector<int> nums = { 2,3,5,9 };
    cout << Solution().minCapability(nums, 2) << "\n";
	return 0;
}