#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        //dp[i][j]表示[i, j]构成回文串所需要进行的操作次数
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = (i + 1 < j ? dp[i + 1][j - 1] : 0);
                }
                else {
                    dp[i][j] = (i + 1 < j ? dp[i + 1][j - 1] + 1 : 1);
                }
            }
        }

        //dfs超时
        /* int mn = 0x3f3f3f3f;
        auto dfs = [&](auto&& dfs, int pos, int cnt, int sum) -> void {
            if (pos == n) {
                if (cnt == k) {
                    mn = min(mn, sum);
                }
                return;
            }

            if (cnt == k - 1) {
                mn = min(mn, sum + dp[pos][n - 1]);
                return;
            }

            for (int i = pos; i < n; i++) {
                dfs(dfs, i + 1, cnt + 1, sum + dp[pos][i]);
            }
        };
        dfs(dfs, 0, 0, 0);*/
        //rets[i][j]表示把[0,j]划分成为i + 1个子串所需要进行的最小修改次数
        vector<vector<int>> rets(k, vector<int>(n, 0x3f3f3f3f));
        rets[0] = dp[0];

        for (int i = 1; i < k; i++) {
            for (int r = i; r <= n - k + i; r++) {
                for (int l = i; l <= r; l++) {
                    rets[i][r] = min(rets[i][r], rets[i - 1][l - 1] + dp[l][r]);
                }
            }
        }
        return rets[k - 1][n - 1];
    }
};

int main() {

	return 0;
}