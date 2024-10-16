#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];

	int left = 0, right = 0;
	int a = nums[0], b = nums.back();
	for (int i = 0; i < n; i++) {
		if (nums[i] == a) ++left;
		else break;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (nums[i] == b) ++right;
		else break;
	}

	if (a == b) {
		if (left + right >= n) cout << 0 << endl;
		else cout << n - left - right << endl;
	}
	else cout << n - max(left, right) << endl;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}