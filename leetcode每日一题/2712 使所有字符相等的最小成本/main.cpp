#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    long long minimumCost(string s) {
        ll ans = 0;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                ans += min(i, n - i);
            }
        }
        return ans;
    }
};

int main() {
	
	return 0;
}