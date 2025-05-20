#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> dp(n);
        for (auto& x : queries) {
            dp[x[0]]++;
            if (x[1] + 1 < n) {
                dp[x[1] + 1]--;
            }
        }

        for (int i = 1; i < n; i++) {
            dp[i] += dp[i - 1];
        }

        for (int i = 0; i < n; i++) {
            nums[i] -= dp[i];
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return false;
        }
        return true;
    }
};

int main() {

	return 0;
}