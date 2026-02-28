#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    using ll = long long;
    int concatenatedBinary(int n) {
        ll ans = 0, len = 0;
        ll a = 4;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) ++len;
            ans = ((ans << len) | i) % MOD;
        }
        return ans;
    }
};

int main() {

	return 0;
}