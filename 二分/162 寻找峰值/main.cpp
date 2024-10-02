#include <iostream>
#include <vector>
using namespace std;
int findPeakElement(vector<int>& nums) {
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		int mid = left + (right - left + 1) / 2;
		if (nums[mid] > nums[mid - 1]) left = mid;
		else right = mid - 1;
	}
	return left;
}

int main() {
	vector<int> nums = { 1,2,3,4,5,6,7,8,9,1};
	cout << nums[findPeakElement(nums)] << endl;
	return 0;
}