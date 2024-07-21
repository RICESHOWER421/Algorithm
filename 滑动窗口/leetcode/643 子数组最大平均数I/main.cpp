#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
	vector<double> dp(nums.size() + 1);
	for (int i = 1; i <= nums.size(); i++)
		dp[i] = dp[i - 1] + nums[i - 1];

	double max_num = INT_MIN;
	for (int i = k; i <= nums.size(); i++)
		max_num = max(max_num, (dp[i] - dp[i - k]) / k);
	return max_num;
}
int main() {

	return 0;
}