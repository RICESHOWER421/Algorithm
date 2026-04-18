#include <bits/stdc++.h>
using namespace std;

//最简单粗暴的方法
//class Solution {
//public:
//    int mirrorDistance(int n) {
//        string tmp = to_string(n);
//        reverse(tmp.begin(), tmp.end());
//        return abs(atoi(tmp.c_str()) - n);
//    }
//};

//先算这个数有多少位，再依次加上对应的数值
class Solution {
public:
    int mirrorDistance(int n) {
        int copy = n, cnt = 0;
        while (copy) {
            ++cnt;
            copy /= 10;
        }

        copy = n;
        int reverse_num = 0;
        while (cnt) {
            reverse_num += (copy % 10) * pow(10, cnt - 1);
            copy /= 10;
            --cnt;
        }
        return abs(reverse_num - n);
    }
};

int main() {

	return 0;
}