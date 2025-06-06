#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class Solution {
public:
    using ll = long long;
    int maxPossibleScore(vector<int>& start, int d) {
        ll n = start.size(), l = 0, r = 0;
        sort(start.begin(), start.end());
        r = start.back() + d;
        auto check = [&](ll pos)->bool {
            ll tmp = start[0];
            for (int i = 1; i < n; i++) {
                if (tmp + pos > (ll)start[i] + (ll)d) return false;
                else tmp = max((ll)start[i], tmp + pos);
            }
            return true;
        };
        while (l < r) {
            ll mid = l + (r - l + 1) / 2;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};

int main() {

    return 0;
}