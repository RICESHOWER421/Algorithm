#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = (int)nums.size() - 1; i >= 2; i--) {
            if (nums[i - 2] + nums[i - 1] > nums[i]) return nums[i] + nums[i - 1] + nums[i - 2];
        }
        return 0;
    }
};

int main() {
	
	return 0;
}