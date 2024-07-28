#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//滑动窗口+位运算
//位运算知识点补充
int longestNiceSubarray(vector<int>& nums) {
	int left = 0, right = left + 1;
	int max_len = 1;
	int num = nums[left];
	while (right < nums.size()) {
		if (!(num & nums[right])) {
			num |= nums[right];
			max_len = max(max_len, right - left + 1);
			++right;
		}
		else {
			num ^= nums[left];
			++left;
			if (left == right) {
				num |= nums[left];
				right = left + 1;
			}
		}
	}
	return max_len;
}

int main() {
	vector<int> nums = { 1,3,8,48,10 };
	cout << longestNiceSubarray(nums) << endl;
	return 0;
}