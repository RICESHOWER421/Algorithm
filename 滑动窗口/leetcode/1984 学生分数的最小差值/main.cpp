#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int minimumDifference(vector<int>& nums, int k) {
	if (k == 1) return 0;

	sort(nums.begin(), nums.end());
	reverse(nums.begin(), nums.end());
	int min_num = INT_MAX;
	for (int i = 0; i <= nums.size() - k; i++)
		min_num = min(min_num, nums[i] - nums[i + k - 1]);
	return min_num;
}

int main() {

	return 0;
}