#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();  
        //dp[i][j]��ʾ��iΪ��㣬��jΪ�յ���Ӵ��Ƿ��ǻ��Ĵ�
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int l = n - 1; l >= 0; l--) {
            for (int r = l; r < n; r++) {
                if (s[l] == s[r]) dp[l][r] = (l + 1 < r ? dp[l + 1][r - 1] : true);
            }
        }

        //f[i]��ʾ��0Ϊ��㣬��iΪ�յ㹹�ɻ��Ĵ���Ҫ����С�ָ����
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