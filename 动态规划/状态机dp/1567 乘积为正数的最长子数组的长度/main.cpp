#include <iostream>
#include <vector>
using namespace std;

int getMaxLen(vector<int>& nums) {
	int n = nums.size();
	vector<int> f(n + 1);
	auto g = f;
	int return_num = INT_MIN;
	
	for (int i = 1; i <= n; i++) {
		if (nums[i - 1] > 0) {
			f[i] = f[i - 1] + 1;
			g[i] = g[i - 1] == 0 ? 0 : g[i - 1] + 1;
		}
		else if (nums[i - 1] < 0) {
			f[i] = g[i - 1] == 0 ? 0 : g[i - 1] + 1;
			g[i] = f[i - 1] + 1;
		}
		
		return_num = max(return_num, f[i]);
	}

	return return_num;
}

int main() {
	vector<int> nums = { 0,1,-2,-3,-4 };
	cout << getMaxLen(nums) << endl;
	return 0;
}