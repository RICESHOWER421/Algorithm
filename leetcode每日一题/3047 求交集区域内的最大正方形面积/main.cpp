#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        vector<pair<pair<int, int>, pair<int, int>>> nums;
        int n = bottomLeft.size();
        for (int i = 0; i < n; i++) {
            nums.push_back({{bottomLeft[i][0], bottomLeft[i][1]}, {topRight[i][0], topRight[i][1]}});
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ll u1 = nums[i].second.second, d1 = nums[i].first.second, l1 = nums[i].first.first, r1 = nums[i].second.first;
                ll u2 = nums[j].second.second, d2 = nums[j].first.second, l2 = nums[j].first.first, r2 = nums[j].second.first;
                if (u1 > u2 && d1 > u2 || u2 > u1 && d2 > u1 || r1 > r2 && l1 > r2 || r2 > r1 && l2 > r1) continue;
                ll umax = min(u1, u2), dmax = max(d1, d2), lmax = max(l1, l2), rmax = min(r1, r2);
                ll ret = min(umax - dmax, rmax - lmax);
                ans = max(ans, ret * ret);
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}