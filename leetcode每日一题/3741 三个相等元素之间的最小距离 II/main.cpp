#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        vector<vector<int>> idx(n + 1);
        for (int i = 0; i < n; i++) {
            auto& x = idx[nums[i]];
            if (x.size() < 3) x.push_back(i);
            else if (x.size() == 3) {
                x[0] = x[1];
                x[1] = x[2];
                x[2] = i;
            }
            if (x.size() == 3) ans = min(ans, abs(x[0] - x[1]) + abs(x[1] - x[2]) + abs(x[2] - x[0]));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {

	return 0;
}