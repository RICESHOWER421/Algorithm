#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int cnt1 = 0, cnt2 = 0, sz1 = hBars.size(), sz2 = vBars.size();
        int mx1 = 1, mx2 = 1;
        for (int i = 0; i < sz1; i++) {
            if (!cnt1) ++cnt1;
            else {
                if (hBars[i] == hBars[i - 1] + 1) ++cnt1;
                else {
                    mx1 = max(mx1, cnt1);
                    cnt1 = 1;
                }
            }
        }
        mx1 = max(mx1, cnt1);

        for (int i = 0; i < sz2; i++) {
            if (!cnt2) ++cnt2;
            else {
                if (vBars[i] == vBars[i - 1] + 1) ++cnt2;
                else {
                    mx2 = max(mx2, cnt2);
                    cnt2 = 1;
                }
            }
        }
        mx2 = max(mx2, cnt2);

        int ans = min(mx1, mx2);
        return (ans + 1) * (ans + 1);
    }
};

int main() {

	return 0;
}