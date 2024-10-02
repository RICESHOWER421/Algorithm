#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int>& nums) {
	int n = nums.size();
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] > nums[n - 1]) left = mid + 1;
		else right = mid;
	}
	return nums[right];
}

int main() {
	vector<int> nums = {1,2,3,4,5,6};
	cout << findMin(nums) << endl;
	return 0;
}