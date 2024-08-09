#include <iostream>
#include <vector>
using namespace std;

//直接套用最长递增子序列的贪心写法，贪心+二分秒了
bool increasingTriplet(vector<int>& nums) {
	vector<int> ret;
	ret.push_back(nums[0]);
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] > ret.back()) ret.push_back(nums[i]);
		else {
			int left = 0, right = ret.size() - 1;
			while (left < right) {
				int mid = left + (right - left) / 2;
				if (nums[i] <= ret[mid]) right = mid;
				else left = mid + 1;
			}
			ret[left] = nums[i];
		}
	}
	return ret.size() >= 3;
}

int main() {

	return 0;
}