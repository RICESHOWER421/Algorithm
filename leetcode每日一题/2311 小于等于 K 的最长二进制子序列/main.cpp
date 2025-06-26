#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = 0, tmp = k;
        while (tmp) {
            ++n;
            tmp /= 2;
        }

        if (n > s.size()) return s.size();
        int len = s.size(), sum = 0, ans = 0;
        bool ok = true;
        for (int i = len - 1; i >= len - n; i--) {
            sum += (s[i] == '1' ? 1 : 0) * pow(2, len - i - 1);
            // cout << sum << " ";
            if (sum > k) {
                ok = false;
                break;
            }
        }

        int ret = ok ? len - n - 1 : len - n;
        ans += (ok ? n : n - 1);
        // cout << ans << "\n";
        for (int i = 0; i <= ret; i++) {
            if (s[i] == '0') ++ans;
        }
        return ans;
    }
};

int main() {

	return 0;
}