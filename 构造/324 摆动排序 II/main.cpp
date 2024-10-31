#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ret;

        int left = nums.size() / 2 - (nums.size() % 2 == 0), right = nums.size() - 1;
        while (right > nums.size() / 2 - (nums.size() % 2 == 0)) {
            ret.push_back(nums[left]);
            ret.push_back(nums[right]);
            --left;
            --right;
        }
        if (nums.size() % 2) ret.push_back(nums[left]);
        nums = ret;
    }
};

int main() {

	return 0;
}