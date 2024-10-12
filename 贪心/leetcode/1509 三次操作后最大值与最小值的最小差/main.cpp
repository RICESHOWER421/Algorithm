#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if ((int)nums.size() <= 4) return 0;
        sort(nums.begin(), nums.end());

        int ans = INT_MAX;
        int n = nums.size();
        for (int i = 0; i <= 3; i++) {
            ans = min(ans, nums[n - 1 - i] - nums[3 - i]);
        }
        return ans;
    }
};

int main() {

	return 0;
}