#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();  
        //dp[i][j]表示以i为起点，以j为终点的子串是否是回文串
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int l = n - 1; l >= 0; l--) {
            for (int r = l; r < n; r++) {
                if (s[l] == s[r]) dp[l][r] = (l + 1 < r ? dp[l + 1][r - 1] : true);
            }
        }

        //f[i]表示以0为起点，以i为终点构成回文串需要的最小分割次数
        vector<int> f(n);
        for (int r = 0; r < n; r++) {
            if (!dp[0][r]) {
                int cnt = 0x3f3f3f3f;
                for (int l = 1; l <= r; l++) {
                    if (dp[l][r]) {
                        cnt = min(cnt, f[l - 1] + 1);
                    }
                }
                f[r] = cnt;
            }
        }
        return f[n - 1];
    }
};

int main() {
    cout << Solution().minCut("aab") << "\n";
	return 0;
}