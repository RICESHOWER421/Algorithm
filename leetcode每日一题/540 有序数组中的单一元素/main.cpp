#include <iostream>
#include <vector>
using namespace std;

//ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)
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

//ʹ�ö��֣���ʱ�临�ӶȽ�ΪO(logn)
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