#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int mx = -1, mn = 0x3f3f3f3f;
        for (char i = '0'; i <= '9'; i++) {
            for (char j = '0'; j <= '9'; j++) {
                if ((i == s[0] && j == '0') || i == j) continue;
                string tmp = s;
                for (int k = 0; k < tmp.size(); k++) {
                    if (tmp[k] == i) tmp[k] = j;
                }
                mx = max(mx, atoi(tmp.c_str()));
                mn = min(mn, atoi(tmp.c_str()));
            }
        }
        return mx - mn;
    }
};

int main() {

	return 0;
}