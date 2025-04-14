#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;
    ll my_pow(ll a, ll b, ll MOD) {
        ll ans = 1, base = a % MOD;
        while (b) {
            if (b % 2) {
                ans = (ans * base) % MOD;
            }
            base = base * base % MOD;
            b /= 2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        ll ans = 1, l = n / 2 + (n % 2), r = n / 2;
        ans = ans * my_pow(5, l, MOD) * my_pow(4, r, MOD) % MOD;
        return ans;
    }
};

int main() {

	return 0;
}