#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        ll n = arr.size(), mx = 0;
        vector<ll> dp(n);   //dp[i]表示下标以i往前所能得到的最大和，注意这里下标从0开始，方便后续运算
        dp[0] = arr[0], mx = max(dp[0], (ll)0);
        for (int i = 1; i < n; i++) {
            dp[i] = max((ll)arr[i], dp[i - 1] + arr[i]);
            mx = max(mx, dp[i]);
        }
        if (k == 1) {
            return mx;
        }
        ll ret = max(dp.back(), (ll)0);
        for (int i = 0; i < n; i++) {
            dp[i] = max((ll)arr[i], arr[i] + dp[(n + i - 1) % n]);
            mx = max(mx, dp[i]);
        }
        ret = max(dp.back(), (ll)0) - ret;
        return (mx + ret * (k - 2) % MOD) % MOD;
    }
};

int main() {
    vector<int> nums = { 5,7,3,8,6,9,4,1,-1231,-123,312,2344,2545,43,34,5,10000 };
    cout << Solution().kConcatenationMaxSum(nums, 1) << "\n";
	return 0;
}