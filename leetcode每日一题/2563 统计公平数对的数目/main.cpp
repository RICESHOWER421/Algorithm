#include <iostream>
#include <vector>
#include <algorithm>
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
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        long long ans = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            int left_index = Binary_Search(nums, lower - nums[i]);
            int right_index = Binary_Search(nums, upper - nums[i] + 1);
            ans += (right_index - left_index - (i >= left_index && i < right_index));
        }
        return ans / 2;
    }
};

int main() {
   
    return 0;
}