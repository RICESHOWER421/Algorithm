#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9 + 7;
    int numberOfArrays(string s, int k) {
        int n = s.size();
        //dp[i]表示前i个字符所能构成的数组种类数
        vector<ll> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            ll sum = 0;
            for (int j = i; j > 0 && i - j <= 8; j--) {
                sum += (s[j - 1] - '0') * pow(10, i - j);
                if (sum <= k) {
                    if (s[j - 1] != '0') {
                        dp[i] = (dp[i] + dp[j - 1]) % MOD;
                    }
                }
                else {
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    cout << Solution().numberOfArrays("1000", 10000) << "\n";
	return 0;
}