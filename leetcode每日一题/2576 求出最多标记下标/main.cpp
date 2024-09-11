#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxNumOfMarkedIndices(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	int ans = 0;
	int n = nums.size();
	int left = n / 2 - 1, right = n - 1;
	while (left >= 0 && right >= n / 2) {
		if (nums[left] * 2 <= nums[right]) {
			ans += 2;
			--right;
		}
		--left;
	}
	return ans;
}

int main() {
	vector<int> nums = { 3,5,2,4 };
	cout << maxNumOfMarkedIndices(nums) << endl;
	return 0;
}