#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//排序做法，时间复杂度不是最优解
//class Solution {
//public:
//    int minimumCost(vector<int>& nums) {
//        sort(nums.begin() + 1, nums.end());
//        return nums[0] + nums[1] + nums[2];
//    }
//};

//时间复杂度为O(N)
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0], n = nums.size();
        int mn = nums[1], index = 1;
        for (int i = 2; i < n; i++) {
            if (nums[i] < mn) {
                mn = nums[i];
                index = i;
            }
        }
        ans += mn;
        int tmp = 51;
        for (int i = 1; i < n; i++) {
            if (nums[i] == mn) {
                if (i != index) return ans + nums[i];
            }
            else tmp = min(tmp, nums[i]);
        }
        return ans + tmp;
    }
};

int main() {

	return 0;
}