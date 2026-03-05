#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size(), ans = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ++cnt;
            }
            else {
                if (cnt) {
                    ++ans;
                    cnt = 0;
                }
            }
        }
        if (cnt) ++ans;
        return ans < 2;
    }
};

int main() {

	return 0;
}