#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx = 0, mn = 0, ans = 0;
        for (auto& x : nums) {
            mx = max(mx, 0) + x;
            mn = min(mn, 0) + x;
            ans = max(ans, max(abs(mx), abs(mn)));
        }
        return ans;
    }
};

int main() {
    vector<int> nums = { 1,-3,2,3,-4 };
    cout << Solution().maxAbsoluteSum(nums) << "\n";
	return 0;
}