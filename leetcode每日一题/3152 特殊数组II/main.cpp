#include <iostream>
#include <vector>
using namespace std;

//0 1 1 0
//0 0 1 1
//1 1
//0 1
//1 0 1 0 1 0 1 0 1 1 0 0 1
//0 0 0 0 0 0 0 0 0 1 1 2 2
vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
	vector<int> dp(nums.size());
	for (int i = 1; i < nums.size(); i++) {
		dp[i] = dp[i - 1] + (nums[i] % 2 == nums[i - 1] % 2);
	}

	vector<bool> ans(queries.size());
	for (int i = 0; i < queries.size(); i++) {
		ans[i] = (dp[queries[i][0]] == dp[queries[i][1]]);
	}
	return ans;
}
int main() {

	return 0;
}