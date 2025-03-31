#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        while (l < r) {
            int mid = l + (r - l) / 2, cnt = 0;
            for (int i = 1; i <= m; i++) {
                cnt += min(mid / i, n);
            }
            if (cnt >= k) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main() {

	return 0;
}