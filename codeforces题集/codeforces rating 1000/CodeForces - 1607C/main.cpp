#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];

	sort(nums.begin(), nums.end());
	
	int max_num = nums[0];
	int ret = nums[0];
	for (int i = 1; i < n; i++) {
		nums[i] -= ret;
		max_num = max(max_num, nums[i]);
		ret += nums[i];
	}
	cout << max_num << endl;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}