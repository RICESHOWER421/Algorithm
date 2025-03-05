#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        //dp[i]表示前i个数字的最小代价
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            unordered_map<int, int> hash_map;
            int cnt = 0;
            dp[i] = 0x3f3f3f3f;
            for (int j = i; j > 0; j--) {
                hash_map[nums[j - 1]]++;
                if (hash_map[nums[j - 1]] == 2) {
                    cnt += 2;
                }
                else if (hash_map[nums[j - 1]] > 2) {
                    ++cnt;
                }
                dp[i] = min(dp[i], dp[j - 1] + cnt + k);
            }
        }
        return dp[n];
    }
};

int main() {

	return 0;
}