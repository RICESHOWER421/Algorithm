#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int findLengthOfLCIS(vector<int>& nums) {
	int ans = 1;
	int left = 0;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] > nums[i - 1]) ans = max(ans, i - left + 1);
		else left = i;
	}
	return ans;
}
int main() {

	return 0;
}