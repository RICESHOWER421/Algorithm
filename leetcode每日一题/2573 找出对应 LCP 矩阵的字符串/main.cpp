#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string ans(n, 'a');
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] > n - i || lcp[i][j] > n - j || lcp[i][j] != lcp[j][i]) return "";
                //如果[i,n - 1],[j,n - 1]子串最长公共前缀为a,那么[i + 1, n - 1],[j + 1, n - 1]子串最长公共前缀为a - 1
                if (i && j && lcp[i - 1][j - 1] && lcp[i - 1][j - 1] - lcp[i][j] != 1) return "";
                if (!lcp[i][j]) { //lcp[i][j]为0,ans[i]和ans[j]一定不能相等
                    if (ans[i] == ans[j]) ++ans[j];
                    if (ans[j] > 'z') return "";
                }
                else {
                    if (ans[i] != ans[j]) return "";
                }
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}