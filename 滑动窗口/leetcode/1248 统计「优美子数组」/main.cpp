#include <iostream>
#include <vector>
using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
	vector<int> odd;
	int ret = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] % 2 == 0) ++ret;
		else {
			odd.push_back(ret);
			ret = 0;
		}
	}
	odd.push_back(ret);

	int ans = 0;
	if (k == 0) {
		for (int i = 0; i < odd.size(); i++) {
			ans += ((odd[i] * (1 + odd[i])) / 2);
		}
	}
	else {
		int sum = 0, left = 0, index = 0;
		for (int i = 0; i < nums.size(); ) {
			if (sum + (nums[i] % 2) <= k) {
				sum += (nums[i] % 2);
				if (sum == k) ans += (odd[index] + 1);
				++i;
			}
			else {
				sum -= (nums[left++] % 2);
				if (sum < k) ++index;
			}
		}
	}
	return ans;
}

int main() {
	vector<int> nums = {1,1,0,1,1};
	int k = 3;
	cout << numberOfSubarrays(nums, k) << endl;
	return 0;
}