#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) {
	int n = nums.size();
	int left = 0, right = left;
	int min_len = INT_MAX;
	int sum = 0, len = 0;
	while (left <= n - 1) {
		if (sum < target && right <= n - 1) {
			sum += nums[right++];
			++len;
		}
		else {
			if (sum >= target) {
				min_len = min(min_len, len);
			}
			len -= 1;
			sum -= nums[left++];
		}
	}
	return min_len == INT_MAX ? 0 : min_len;
}

int main() {
	vector<int> nums = { 5,6,7,8,9 };
	cout << minSubArrayLen(4, nums) << endl;
	return 0;
}