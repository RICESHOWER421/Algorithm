#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int mx = 0;
        while (left < right) {
            mx = max(mx, nums[left] + nums[right]);
            ++left;
            --right;
        }
        return mx;
    }
};

int main() {

	return 0;
}