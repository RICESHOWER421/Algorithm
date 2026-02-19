#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size(), c1 = 1, c2 = 0, ans = 0;
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                if (ok) ++c1;
                else ++c2;
            }
            else {
                ok = false;
                if (c1 && c2) {
                    ans += min(c1, c2);
                    c1 = c2;
                    c2 = 1;
                }
                else ++c2;
            }
        }
        return ans + min(c1, c2);
    }
};

int main() {

	return 0;
}