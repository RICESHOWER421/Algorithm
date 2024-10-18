#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            if (!nums[i]) {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ++ans;
            }
        }
        return nums[n - 1] && nums[n - 2] && nums[n - 3] ? ans : -1;
    }
};

int main() {
    vector<int> nums = { 0,1,1,1,0,0 };
    cout << Solution().minOperations(nums) << endl;
	return 0;
}