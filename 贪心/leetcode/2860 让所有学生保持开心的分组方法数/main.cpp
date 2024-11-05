#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1 1 4 5 1 4 1 9 1 9 8 1 0
//0 1 1 1 1 1 1 4 4 5 8 9 9
int countWays(vector<int>& nums) {
    int ret = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] < i + 1 && i + 1 < nums[i + 1]) ++ret;
    }

    return (nums[0] == 0 ? 0 : 1) + (nums.size() > nums.back() ? 1 : 0) + ret;
}

int main() {
    vector<int> nums = { 1,1,4,5,1,4,1,9,1,9,8,1,0 };
    cout << countWays(nums) << endl;
	return 0;
}