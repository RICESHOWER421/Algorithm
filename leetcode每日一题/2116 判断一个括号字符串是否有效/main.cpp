#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2) {
            return false;
        }

        //mn表示左括号的最小可能出现次数，mx表示左括号的最大可能出现次数
        //需要注意的是，所有可能出现的次数一定是连续的同奇偶性，所以我们要以此作为判断条件
        int mn = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '1') {
                int tmp = s[i] == '(' ? 1 : -1;
                mx += tmp;
                if (mx < 0) { //说明此时不存在合理解
                    return false;
                }
                mn += tmp;
            }
            else {
                ++mx;
                --mn;
            }
            if (mn < 0) {
                mn = 1;
            }
        }
        return mn == 0;
    }
};


int main() {
    string s = "((()(()()))()((()()))))()((()(()", ret = "10111100100101001110100010001001";
    cout << Solution().canBeValid(s, ret) << "\n";
	return 0;
}