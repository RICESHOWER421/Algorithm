#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        auto check = [&](char a, char b)->int {
            int cnt = 0, ret = k, pos = -1;
            for (int i = 0; i < n; i++) {
                if (s[i] == a || s[i] == b) ++cnt;
                else {
                    if (ret) {
                        --ret;
                        ++cnt;
                    }
                    else {
                        pos = i;
                        break;
                    }
                }
            }

            int mx = cnt;
            if (pos != -1) {
                for (int i = pos; i < n; i++) {
                    if (s[i] == a || s[i] == b) ++cnt;
                    else --cnt;
                    mx = max(mx, cnt);
                }
            }
            return mx;
        };
        return max({ check('E','N'), check('E','S'), check('W', 'N'), check('W', 'S') });
    }
};

int main() {

	return 0;
}