#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

long long maximumSubarraySum(vector<int>& nums, int k) {	
	map<int, int> hash_map;

	long long sum = 0;
	long long num = 0;
	for (int i = 0; i < k; i++) {
		sum += nums[i];
		if (!hash_map.count(nums[i])) ++num;
		++hash_map[nums[i]];
	}

	long long ret = num == k ? sum : 0;
	for (int i = k; i < nums.size(); i++) {
		sum = sum + nums[i] - nums[i - k];
		if (!hash_map[nums[i]])++num;
		++hash_map[nums[i]];
		--hash_map[nums[i - k]];
		if (!hash_map[nums[i - k]]) --num;
		if (num == k) ret = max(ret, sum);
	} 
	return ret;
}

int main() {

	return 0;
}