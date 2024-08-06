#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int longestEqualSubarray(vector<int>& nums, int k) {
	map<int, vector<int>> hash_map;
	vector<int> arr;
	for (int i = 0; i < nums.size(); i++) {
		if (!hash_map.count(nums[i])) arr.push_back(nums[i]);
		hash_map[nums[i]].push_back(i);
	}

	int ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		int ret = 0, sum = 0, left = 0;
		for (int j = 0; j < hash_map[arr[i]].size(); j++) {
			++ret;
			if (j >= 1) {
				sum += (hash_map[arr[i]][j] - hash_map[arr[i]][j - 1] - 1);
				if (sum > k) {
					while (sum > k) {
						--ret;
						sum -= (hash_map[arr[i]][left + 1] - hash_map[arr[i]][left] - 1);
						++left;
					}
				}
			}
			ans = max(ans, ret);
		}
	}
	return ans;
}

int main() {
	vector<int> nums = { 6,4,7,6,4,8,6,6 };
	int k = 1;
	cout << longestEqualSubarray(nums, k) << endl;
	return 0;
}