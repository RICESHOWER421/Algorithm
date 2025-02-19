#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mx1 = -(1e5 + 10), mx2 = -(1e5 + 10), mn1 = 1e5 + 10, mn2 = 1e5 + 10;
        int cnt1 = 0, cnt2 = 0;
        bool ok = false;
        for (auto& x : arrays) {
            if (x[0] < mn1) {
                if (mn1 != 1e5 + 10) {
                    mn2 = mn1;
                    cnt1 = 0;
                }
                mn1 = x[0];
            }
            else {
                if (x[0] < mn2) {
                    mn2 = x[0];
                }
            }

            if (x.back() > mx1) {
                if (mx1 != -1) {
                    mx2 = mx1;
                    cnt2 = 0;
                }
                mx1 = x.back();
            }
            else {
                if (x.back() > mx2) {
                    mx2 = x.back();
                }
            }

            if (x[0] == mn1) ++cnt1;
            if (x.back() == mx1) ++cnt2;
        }

        for (auto& x : arrays) {
            if (x[0] == mn1 && x.back() == mx1) {
                ok = true;
                break;
            }
        }

        if (cnt1 == 1 && cnt2 == 1 && ok) {
            return max(mx2 - mn1, mx1 - mn2);
        }
        else {
            return mx1 - mn1;
        }
    }
};

int main() {
    vector<vector<int>> arrays = { {-3,-3},{-3,-2} };
    cout << Solution().maxDistance(arrays) << "\n";
	return 0;
}