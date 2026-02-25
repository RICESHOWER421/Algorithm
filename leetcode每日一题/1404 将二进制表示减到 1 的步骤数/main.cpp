#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int ans = 0, cnt = 0;   //cnt表示连续1的个数
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') ++cnt;
            else {
                ++ans;
                if (cnt) {
                    ans += cnt;
                    cnt = 1;
                }
            }
        }
        return cnt == 1 ? ans : ans + cnt + 1;  //当cnt恒等于1时，说明此时只有最开头的1
    }
};

int main() {

	return 0;
}