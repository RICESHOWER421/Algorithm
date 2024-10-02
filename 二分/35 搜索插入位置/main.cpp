#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] < target) left = mid + 1;
		else right = mid;
	}
	if (right == nums.size() - 1 && target > nums[right]) return right + 1;
	else return right;
}

int main() {
	vector<int> nums = { 1 };
	cout << searchInsert(nums, 2) << endl;
	return 0;
}