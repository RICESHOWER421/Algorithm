#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> val(26, 1001);
        for (int i = 0; i < chars.size(); i++) {
            val[chars[i] - 'a'] = vals[i];
        }

        for (int i = 0; i < 26; i++) {
            if (val[i] == 1001) {
                val[i] = i + 1;
            }
        }

        int n = s.size(), mx = 0;
        vector<int> dp(n + 1);  //dp[i]表示前i个数字所能获得的最大值
        for (int i = 1; i <= n; i++) {
            dp[i] = max(val[s[i - 1] - 'a'], dp[i - 1] + val[s[i - 1] - 'a']);
            mx = max(dp[i], mx);
        }
        return mx;
    }
};

int main() {

	return 0;
}