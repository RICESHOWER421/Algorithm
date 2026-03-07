#include <bits/stdc++.h>
using namespace std;

//前缀和写法，大约200ms执行完成
class Solution {
public:
    int minFlips(string s) {
        int n = s.size(), ans = 0;
        vector<vector<int>> pre(n + 1, vector<int>(2));     //0表示1开头的交替字符串,1表示0开头的交替字符串
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1') {
                if (i % 2 == 0) {
                    pre[i][0] = pre[i - 1][0] + 1;
                    pre[i][1] = pre[i - 1][1];
                }
                else {
                    pre[i][1] = pre[i - 1][1] + 1;
                    pre[i][0] = pre[i - 1][0];
                }
            }
            else {
                if (i % 2) {
                    pre[i][0] = pre[i - 1][0] + 1;
                    pre[i][1] = pre[i - 1][1];
                }
                else {
                    pre[i][1] = pre[i - 1][1] + 1;
                    pre[i][0] = pre[i - 1][0];
                }
            }
            //cout << pre[i][0] << " " << pre[i][1] << "\n";
        }
        ans = min(pre[n][0], pre[n][1]);

        for (int i = 1; i <= n; i++) {
            if (n % 2) {  //交替字符串最后一个字符一定和最开始的不一样
                ans = min(ans, pre[n][0] - pre[i][0] + pre[i][1]);
                ans = min(ans, pre[n][1] - pre[i][1] + pre[i][0]);
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}