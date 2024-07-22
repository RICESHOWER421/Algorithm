#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

long long maxSum(vector<int>& nums, int m, int k) {
	map<int, int> hash_map;

	long long num = 0, sum = 0;
	for (int i = 0; i < k; i++) {
		if (!hash_map.count(nums[i])) ++num;
		hash_map[nums[i]]++;
		sum += nums[i];
	}

	long long ret = num >= m ? sum : 0;
	for (int i = k; i < nums.size(); i++) {
		sum = sum + nums[i] - nums[i - k];
		if (!hash_map.count(nums[i]))++num;
		++hash_map[nums[i]];
		--hash_map[nums[i - k]];
		if (!hash_map[nums[i - k]]) --num;
		if (num >= m) ret = max(ret, sum);
	}
	return ret;
}

int main() {
	vector<int> nums = { 1,3,1,4 };
	int m = 1,k = 1;
	cout << maxSum(nums, m, k) << endl;
	return 0;
}