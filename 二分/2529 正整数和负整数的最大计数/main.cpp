#include <iostream>
#include <vector>
using namespace std;

//第一种方法：直接遍历
//class Solution {
//public:
//    int maximumCount(vector<int>& nums) {
//        int left = 0, right = (int)nums.size() - 1;
//        int ret_1 = 0, ret_2 = 0;
//        while (left < (int)nums.size() && nums[left] < 0) {
//            ++left;
//            ++ret_1;
//        }
//
//        while (right >= 0 && nums[right] > 0) {
//            --right;
//            ++ret_2;
//        }
//        return max(ret_1, ret_2);
//    }
//};

//第二种方法：二分 
class Solution {
public:
    int BinarySearch(vector<int>& nums, int find) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < find) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    int maximumCount(vector<int>& nums) {
        int left = BinarySearch(nums, 0);
        int right = BinarySearch(nums, 1);
        return max(left, (int)nums.size() - right);
    }
};

int main() {

	return 0;
}