#include <bits/stdc++.h>
using namespace std;

//方法一：将问题拆分成子问题逐个求解
class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        if (k == (1 << (n - 1))) return '1';
        if (k < (1 << (n - 1))) return findKthBit(n - 1, k);
        else return findKthBit(n - 1, (1 << n) - k) ^ 1;    //由ASCII值可知，'0'字符值为48，与1异或为'1'（49）
    }
};

//方法二：直接暴力模拟
class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i = 0; i < n - 1; i++) {
            string tmp = s;
            for (int j = 0; j < (int)tmp.size(); j++) {
                if (tmp[j] == '1') tmp[j] = '0';
                else tmp[j] = '1';
            }
            reverse(tmp.begin(), tmp.end());
            s = s + '1' + tmp;
            // cout << s << "\n";
        }
        return s[k - 1];
    }
};

int main() {

	return 0;
}