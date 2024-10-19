#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mx = nums[0], mn = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }
        
        return mx - mn <= 2 * k ? 0 : mx - k - (mn + k);
    }
};

int main() {

	return 0;
}