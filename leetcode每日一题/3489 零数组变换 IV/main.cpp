#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (num) {
                vector<bool> dp(num + 1);
                dp[0] = true;

                for (int j = 0; j < m; j++) {
                    int l = queries[j][0], r = queries[j][1], tmp = queries[j][2];
                    if (i >= l && i <= r) {
                        for (int k = num; k >= tmp; k--) {  //为什么这里要用逆序遍历？因为本层的状态不能由本层推出
                            dp[k] = dp[k] || dp[k - tmp];
                        }
                    }
                    if (dp[num]) {
                        ans = max(ans, j + 1);
                        break;
                    }
                }
                if (!dp[num]) {
                    return -1;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = { 2,0,2 };
    vector<vector<int>> queries = { {0,2,1},{0,2,1},{1,1,3} };
    cout << Solution().minZeroArray(nums, queries) << "\n";
	return 0;
}