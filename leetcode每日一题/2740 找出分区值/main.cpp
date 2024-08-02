#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int findValueOfPartition(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	int ret = INT_MAX;
	for (int i = 0; i < nums.size() - 1; i++)
		ret = min(ret, abs(nums[i] - nums[i + 1]));
	return ret;
}

int main() {

	return 0;
}