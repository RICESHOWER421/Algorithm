#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
	map<int, int> hash_map;
	int left = 0, right = 0;
	int ret = 0, sum = 0;
	
	while (right < nums.size()) {
		if (hash_map[nums[right]] < 1) {
			++hash_map[nums[right]];
			sum += nums[right];
			ret = max(ret, sum);
			++right;
		}
		else {
			--hash_map[nums[left]];
			sum -= nums[left];
			++left;
		}
	}
	
	return ret;
}

int main() {
	vector<int> nums = { 1,2,3,4,5,6,7,8,9 };
	cout << maximumUniqueSubarray(nums) << endl;
	return 0;
}