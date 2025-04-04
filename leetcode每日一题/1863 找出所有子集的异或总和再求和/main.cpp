#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int sum = 0;
	int path = 0;

	void dfs(vector<int>& nums, int pos) {
		sum += path;

		for (int i = pos; i < nums.size(); i++) {
			path ^= nums[i];
			dfs(nums, i + 1);
			//»ØËÝ
			path ^= nums[i];
		}
	}

	int subsetXORSum(vector<int>& nums) {
		dfs(nums, 0);
		return sum;
	}
};

int main() {

	return 0;
}