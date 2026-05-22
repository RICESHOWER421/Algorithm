#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[0]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        if (l > 0 && nums[l] > nums[l - 1] && target == nums[l]) {
            return l;
        }

        if (target >= nums[0]) {
            l = 0;
            --r;
        }
        else {
            r = n - 1;
        }

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return nums[l] == target ? l : -1;
    }
};

int main() {
    vector<int> nums = { 2,5,6,0,0,1,2};
    int target = 3;
    cout << Solution().search(nums, target) << "\n";
   	return 0;
}