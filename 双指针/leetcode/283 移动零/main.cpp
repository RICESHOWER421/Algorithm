#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void moveZeroes(vector<int>& nums) {
	int n = nums.size();
	int left = 0, right = left;
	while (right != n) {
		if (nums[right] != 0) 
			swap(nums[right], nums[left++]);
		++right;
	}
}

int main() {
	vector<int> nums = {0,0,1,0,0,2,0,0,0,0,};
	moveZeroes(nums);
	for (auto i : nums) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}