#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        //dp[i]表示前i个数字所能获得的最大值
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            int mx = 0;
            for (int j = i; j > 0 && j > i - k; j--) {
                mx = max(arr[j - 1], mx);
                dp[i] = max(dp[i], dp[j - 1] + (i - j + 1) * mx);
            }
        }
        return dp[n];
    }
};

int main() {

	return 0;
}