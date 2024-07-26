#include <iostream>
#include <vector>
using namespace std;

int longestSubarray(vector<int>& nums) {
	int left = 0, right = 0;
	int ret_0 = 0, ret_1 = 0, ans = 0;
	while (right < nums.size()) {
		if (ret_0 == 2) {
			if (nums[left]) --ret_1;
			else --ret_0;
			++left;
			continue;
		}
		if (!nums[right]) ++ret_0;
		else {
			++ret_1;
			ans = max(ans, ret_1);
		}
		++right;
	}
	return ans == nums.size() ? nums.size() - 1 : ans;
}

int main() {
	vector<int> nums = { 1,0,1,1,1,1,1,1,0,0,1,0,1,0,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,0,1,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1 };
	cout << longestSubarray(nums) << endl;
	return 0;
}