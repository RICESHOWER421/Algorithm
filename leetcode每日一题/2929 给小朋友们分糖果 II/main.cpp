#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    ll func(ll num) {
        return num > 1 ? num * (num - 1) / 2 : 0;
    }
    long long distributeCandies(int n, int limit) {
        return func(n + 2) - 3 * func(n - limit + 1) + 3 * func(n - 2 * limit) - func(n - 3 * limit - 1);
    }
};

int main() {

	return 0;
}