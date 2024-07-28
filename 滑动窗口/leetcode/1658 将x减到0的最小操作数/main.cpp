#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minOperations(vector<int>& nums, int x) {
	int n = nums.size();
	int left = 0, right = 0, max_len = INT_MIN;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += nums[i];
	}
	if (sum < x) return -1;

	int temp = 0;
	while (left <= n - 1) {
		if (temp < sum - x && right <= n - 1) temp += nums[right++];
		else {
			if (temp == sum - x) {
				max_len = max(max_len, right - left);
			}
			temp -= nums[left++];
		}
	}

	return max_len == INT_MIN ? -1 : n - max_len;
}

int main() {
	vector<int> nums = { 1,1 };
	cout << minOperations(nums, 3) << endl;
	return 0;
}