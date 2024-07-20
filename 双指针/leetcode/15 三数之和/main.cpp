#include <iostream>
#include <vector>
#include <algorithm>


//优化起来非常复杂（筛出重复数组）
//值得注意的是，直接暴力筛选是可以筛选出来的
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
	int n = nums.size();
	sort(nums.begin(), nums.end());
	vector<vector<int>> return_nums;
	for (int i = n - 1; i >= 2; i--) {
		if (nums[i] < 0) {
			break;
		}
		if (i != n - 1 && nums[i] == nums[i + 1]) {
			continue;
		}
		else {
			int left = 0, right = i - 1;
			while (left < right) {
				if (nums[left] + nums[right] + nums[i] == 0) {
					if (right != i - 1 && nums[right] == nums[right + 1]) {
						--right;
					}
					else {
						return_nums.push_back({ nums[left], nums[right], nums[i] });
						--right;
					}
				}
				else {
					if (nums[left] + nums[right] + nums[i] < 0) {
						++left;
					}
					else {
						--right;
					}
				}
			}
		}
	}
	return return_nums;
}

int main() {
	vector<int> nums = { -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 };
	vector<vector<int>> return_nums = threeSum(nums);
	for (int i = 0; i < return_nums.size(); i++) {
		for (int j = 0; j < return_nums[0].size(); j++) {
			cout << return_nums[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}