#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll sum = 0, l = lower, r = upper;
        for (auto& x : differences) {
            sum += x;
            l = max(l, lower - sum);
            r = min(r, upper - sum);
        }
        return r - l + 1 <= 0 ? 0 : r - l + 1;
    }
};

int main() {

	return 0;
}