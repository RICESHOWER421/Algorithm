#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string triangleType(vector<int>& nums) {
    if (nums[0] == nums[1] && nums[0] == nums[2] && nums[1] == nums[2]) return "equilateral";
    else {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2]) return "none";
        else {
            if (nums[0] == nums[1] || nums[0] == nums[2] || nums[1] == nums[2]) return "isosceles";
            else return "scalene";
        }
    }
}

int main() {

    return 0;
}