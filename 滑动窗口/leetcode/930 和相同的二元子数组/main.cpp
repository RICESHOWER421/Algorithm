#include <iostream>
#include <vector>
using namespace std;

//0 0 0 1 1 0 0 1 0 1 0 0 1 1 1 1 0 1
//2
int numSubarraysWithSum(vector<int>& nums, int goal) {
	vector<int> zeros;
	int ret = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 0) ++ret;
		else {
			zeros.push_back(ret);
			ret = 0;
		}
	}
	zeros.push_back(ret);

	int ans = 0;
	if (goal == 0) {
		for (int i = 0; i < zeros.size(); i++) {
			ans += ((zeros[i] * (1 + zeros[i])) / 2);
		}
	}
	else {
		int sum = 0, left = 0, index = 0;
		for (int i = 0; i < nums.size(); ) {
			if (sum + nums[i] <= goal) {
				sum += nums[i];
				if (sum == goal) ans += (zeros[index] + 1);
				++i;
			}
			else {
				sum -= nums[left++];
				if (sum < goal) ++index;
			}
		}
	}
	return ans;
}

int main() {
	vector<int> nums = { 1,0,1,0,1 };
	int goal = 2;
	cout << numSubarraysWithSum(nums, goal) << endl;
	return 0;
}