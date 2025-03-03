#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int crackNumber(int ciphertext) {
        string s = to_string(ciphertext);
        int n = s.size();
        //dp[i]表示前i个数字所能组成的解密方式
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] += dp[i - 1];
            if (i >= 2) {
                if (s[i - 2] == '1') {
                    dp[i] += dp[i - 2];
                }
                else if (s[i - 2] == '2') {
                    if (s[i - 1] >= '0' && s[i - 1] <= '5') {
                        dp[i] += dp[i - 2];
                    }
                }
            }
        }
        return dp[n];
    }
};

int main() {

	return 0;
}