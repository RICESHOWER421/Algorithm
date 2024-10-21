#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = nums.back() - nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            int mx = max(nums[i - 1] + k, nums.back() - k);
            int mn = min(nums[i] - k, nums[0] + k);
            ans = min(ans, mx - mn);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main() {

	return 0;
}
