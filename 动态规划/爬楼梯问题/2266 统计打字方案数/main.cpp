#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        vector<int> nums(10);
        for (int i = 2; i <= 9; i++) {
            nums[i] = 3;
        }
        nums[7] = nums[9] = 4;

        pressedKeys = " " + pressedKeys;
        vector<ll> dp(n + 1);   //dp[i]表示长度为i的字符串的不同解读方式
        dp[0] = 1;
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            if (pressedKeys[i] == pressedKeys[i - 1]) {
                ++ret;
                ret = min(ret, nums[pressedKeys[i] - '0']);
            }
            else ret = 1;

            for (int j = 1; j <= ret; j++) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
        return dp.back();
    }
};

int main() {
    cout << Solution().countTexts("222222222222222222222222222222222222") << "\n";
	return 0;
}