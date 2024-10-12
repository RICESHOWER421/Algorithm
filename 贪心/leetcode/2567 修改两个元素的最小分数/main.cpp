#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        return min({ nums.back() - nums[2], nums[n - 2] - nums[1], nums[n - 3] - nums[0] });
    }
};

int main() {

	return 0;
}