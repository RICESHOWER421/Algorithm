#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
	int n = nums.size();
	int left = 0, right = left, zero = 0;
	int max_len = INT_MIN;
	while (right <= n - 1) {
		if (nums[right] == 0) ++zero;
		while (zero > k)
			if (nums[left++] == 0) --zero;
		max_len = max(max_len, right - left + 1);
		++right;
	}
	return max_len;
}

int main() {
	vector<int> nums = { 1,1,1,0,0,0,1,1,1,1,0 };
	cout << longestOnes(nums, 2) << endl;
	return 0;
}