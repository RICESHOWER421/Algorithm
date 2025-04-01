#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    long long maximumTotalDamage(vector<int>& power) {  
        map<int, ll> hash_map;
        vector<ll> nums;
        for (auto& x : power) {
            if (!hash_map.count(x)) nums.push_back(x);
            hash_map[x]++;
        }
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<ll> dp(n + 1);   //dp[i]表示前i种咒语所能造成的最大伤害
        dp[1] = nums[0] * hash_map[nums[0]];
        for (int i = 2; i <= n; i++) {
            int cur = i - 2;
            while (cur >= 0 && nums[i - 1] - nums[cur] <= 2) {
                --cur;
            }
            dp[i] = max(dp[i - 1], nums[i - 1] * hash_map[nums[i - 1]] + dp[cur + 1]);
        }
        return dp.back();
    }
};

int main() {
    vector<int> nums = { 7,1,6,6 };
    cout << Solution().maximumTotalDamage(nums) << "\n";
	return 0;
}