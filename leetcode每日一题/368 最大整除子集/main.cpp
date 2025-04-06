#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, vector<int>>> dp(n);  //dp[i]表示以i为结尾的最大整除子集
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                int tmp = nums[i] % nums[j] == 0 ? dp[j].first + 1 : 0;
                if (tmp > dp[i].first) {
                    dp[i].first = tmp;
                    dp[i].second = dp[j].second;
                }
            }
            dp[i].second.push_back(nums[i]);
        }

        vector<int> ans;
        int mx = 0;
        for (auto& x : dp) {
            if (x.first > mx) {
                mx = x.first;
                ans = x.second;
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}