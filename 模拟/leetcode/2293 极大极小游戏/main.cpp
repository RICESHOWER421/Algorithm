#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int minMaxGame(vector<int>& nums) {
	if (nums.size() == 1) return nums[0];
	int time = 0, temp = 1;
	while (temp != nums.size()) {
		temp *= 2;
		++time;
	}

	while (time--) {
		for (int i = 0; i < nums.size() / 2; i++) {
			if (i % 2) nums[i] = max(nums[2 * i], nums[2 * i + 1]);
			else nums[i] = min(nums[2 * i], nums[2 * i + 1]);
		}
	}
	return nums[0];
}

int main() {
	vector<int> nums = { 1,3 };
	cout << minMaxGame(nums) << endl;
	return 0;
}