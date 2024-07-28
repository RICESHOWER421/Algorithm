#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxFrequency(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());
	int left = 0, right = 0;
	int max_len = 1;
	int temp = 0, num = nums[0];
	while (right < nums.size()) {
		temp += (nums[right] - num) * (right - left);
		if (nums[left] != nums[right]) num = nums[right];
		if (temp > k) {
			while (temp > k) {
				temp -= (num - nums[left]);
				++left;
			}
		}
		max_len = max(max_len, right - left + 1);
		++right;
	}
	return max_len;
}

int main() {
	vector<int> nums = {1,1,1,1,1,2,2,2,2,2,3,3,3,3,4,4,4};
	int k = 11;
	cout << maxFrequency(nums, k) << endl;
	return 0;
}