#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        //dp[i][j]表示[i,j]是否是回文串
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = (i + 1 < j ? dp[i + 1][j - 1] : true);
                }
            }
        }

        for (int r = 0; r < n; r++) {
            if (dp[0][r]) {
                for (int i = r + 1; i < n - 1; i++) {
                    if (dp[r + 1][i] && dp[i + 1][n - 1]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {

	return 0;
}