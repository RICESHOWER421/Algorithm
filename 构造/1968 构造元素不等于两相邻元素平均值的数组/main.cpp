#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;

        vector<int> ans;
        while (left <= right) {
            if (left == right) {
                ans.push_back(nums[left]);
            }
            else {
                ans.push_back(nums[left]);
                ans.push_back(nums[right]);
            }
            ++left;
            --right;
        }
        return ans;
    }
};

int main() {

	return 0;
}