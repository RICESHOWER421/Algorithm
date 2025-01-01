#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertDateToBinary(string date) {
        int num1 = (atoi(date.substr(0, 4).c_str()));
        int num2 = (atoi(date.substr(5, 2).c_str()));
        int num3 = (atoi(date.substr(8, 2).c_str()));

        string ret1, ret2, ret3, ret;

        while (num1) {
            ret1 += ((num1 & 1) + '0');
            num1 >>= 1;
        }
        reverse(ret1.begin(), ret1.end());
        ret += ret1;
        ret += '-';

        while (num2) {
            ret2 += ((num2 & 1) + '0');
            num2 >>= 1;
        }
        reverse(ret2.begin(), ret2.end());
        ret += ret2;
        ret += '-';

        while (num3) {
            ret3 += ((num3 & 1) + '0');
            num3 >>= 1;
        }
        reverse(ret3.begin(), ret3.end());
        ret += ret3;

        return ret;
    }
};

int main() {

	return 0;
}