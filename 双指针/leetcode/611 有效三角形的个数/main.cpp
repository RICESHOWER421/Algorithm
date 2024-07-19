#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int triangleNumber(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int n = nums.size();
	int sum = 0;
	for (int i = n - 1; i >= 2; i--) {
		int left = 0, right = i - 1;
		while (left < right) {
			if (nums[left] + nums[right] > nums[i]) {
				sum += (right - left);
				--right;
			}
			else {
				++left;
			}
		}
	}
	return sum;
}

int main() {
	vector<int> nums = { 4,2,3,4 };
	cout << triangleNumber(nums) << endl;
	return 0;
}