#include <bits/stdc++.h>
using namespace std;

//ʱ�临�Ӷ�ΪO(N^2)��д��
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        //dp[i]��ʾ��i��β���ܵõ�����ǵݼ������г���
        vector<int> dp(n, 1);
        int mx = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] >= nums[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                    mx = max(dp[i], mx);
                }
            }
        }
        return n - mx;
    }
};

//ʱ�临�Ӷ�ΪO(N)��д��
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(4);
        for (auto& x : nums) {
            dp[x]++;
            dp[2] = max(dp[2], dp[1]);
            dp[3] = max(dp[3], dp[2]);
        }
        return n - max(dp[1], max(dp[2], dp[3]));
    }
};
int main() {
	vector<int> nums = { 1,2,3,2,1,2,3,2,2,2,1,2,3,2,2,2,1,1,1,2,1,3,2,1 };
	cout << Solution().minimumOperations(nums) << "\n";
	return 0;
}