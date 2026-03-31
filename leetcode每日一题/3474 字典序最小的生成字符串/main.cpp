#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string ans(n + m - 1, '?');
        //先解决T的位置，确定下来后永远不能更改
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (ans[i + j] != '?' && str2[j] != ans[i + j]) {
                        return "";
                    }
                    ans[i + j] = str2[j];
                }
            }
        }

        string ori_ans = ans;
        for (auto& x : ans) {
            if (x == '?') x = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F' && ans.substr(i, m) == str2) {
                bool ok = false;
                for (int j = i + m - 1; j >= i; j--) {
                    if (ori_ans[j] == '?') {  //此时ans[j]为a，这里变为b
                        ans[j] = 'b';
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    return "";
                }
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}