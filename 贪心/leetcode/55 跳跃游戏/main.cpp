#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

bool canJump(vector<int>& nums) {
	int left = 0, right = 0, maxPos = 0;
	while (left <= right) {
		if (maxPos >= nums.size() - 1) return true;
		else {
			for (int i = left; i <= right; i++) {
				maxPos = max(maxPos, nums[i] + i);
			}
			left = right + 1;
			right = maxPos;
		}
	}
	return false;
}

int main() {
	vector<int> nums = { 8,0,9,8,7,0,8,7,6,9,6,2,0,1,0,0};
	cout << canJump(nums) << endl;
	return 0;
}