#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void ThreeSum(vector<int>& nums, vector<vector<int>>& return_nums, int end, int target){
	for (int i = end; i >= 2; i--) {
		if (i != end && nums[i] == nums[i + 1]) continue;

		int left = 0, right = i - 1;
		while (left < right) {
			if (nums[left] + nums[right] + nums[i] + nums[end + 1] == target) {
				if (right != i - 1 && nums[right] == nums[right + 1]) {
					--right;
				}
				else {
					return_nums.push_back({ nums[left], nums[right], nums[i], nums[end + 1] });
					--right;
				}
			}
			else if (nums[left] + nums[right] + nums[i] + nums[end + 1] < target) {
				++left;
			}
			else {
				--right;
			}
		}
	}
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> return_nums;
	sort(nums.begin(), nums.end());
	
	int n = nums.size();
	for (int i = n - 1; i >= 3; i--) {
		if (i != n - 1 && nums[i] == nums[i + 1]) continue;
		//三数之和思想
		ThreeSum(nums, return_nums, i - 1, target);
	}
	
	return return_nums;
}

int main() {
	vector<int> nums = { 1000000000,1000000000,1000000000,1000000000 };
	/*vector<vector<int>> return_nums = fourSum(nums, 0);
	for (int i = 0; i < return_nums.size(); i++) {
		for (int j = 0; j < return_nums[0].size(); j++) {
			cout << return_nums[i][j] << " ";
		}
		cout << endl;
	}*/
	long long val = (long long)nums[0] + nums[1] + nums[2] + nums[3];
	cout << val << endl;
	return 0;
}