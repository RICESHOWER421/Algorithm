#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;
    int countHousePlacements(int n) {
        vector<ll> dp(n + 1);   //dp[i]表示前i个位置一共有多少个设计房子方案
        dp[0] = 1, dp[1] = 2;
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
        
        ll ans = dp.back() * dp.back() % MOD;
        return ans;
    }
};

int main() {
    cout << Solution().countHousePlacements(3) << "\n";
	return 0;
}