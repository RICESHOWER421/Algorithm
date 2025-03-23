#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2) {
            return false;
        }

        //mn��ʾ�����ŵ���С���ܳ��ִ�����mx��ʾ�����ŵ������ܳ��ִ���
        //��Ҫע����ǣ����п��ܳ��ֵĴ���һ����������ͬ��ż�ԣ���������Ҫ�Դ���Ϊ�ж�����
        int mn = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '1') {
                int tmp = s[i] == '(' ? 1 : -1;
                mx += tmp;
                if (mx < 0) { //˵����ʱ�����ں����
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