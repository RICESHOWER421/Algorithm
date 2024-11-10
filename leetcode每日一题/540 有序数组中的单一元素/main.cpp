#include <iostream>
#include <vector>
using namespace std;

//时间复杂度为O(n)，空间复杂度为O(1)
//class Solution {
//public:
//    int singleNonDuplicate(vector<int>& nums) {
//        int ret = 0;
//        for (auto& x : nums) {
//            ret ^= x;
//        }
//        return ret;
//    }
//};

//使用二分，将时间复杂度降为O(logn)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[mid ^ 1]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return nums[left];
    }
};

int main() {
    vector<int> nums = { 1 };
    cout << Solution().singleNonDuplicate(nums) << "\n";
	return 0;
}