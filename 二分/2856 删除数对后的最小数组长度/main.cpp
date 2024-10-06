#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int Binary_Search(vector<int>& nums, int find) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < find) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        int left = Binary_Search(nums, nums[n / 2]);
        int right = Binary_Search(nums, nums[n / 2] + 1);
        return max((right - left) * 2 - n, n % 2);
    }
};

int main() {
   
	return 0;
}