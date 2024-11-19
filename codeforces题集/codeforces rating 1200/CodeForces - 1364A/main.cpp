#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void Test() {
	int n = 0, x = 0;
	cin >> n >> x;

	int sum = 0;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		sum += nums[i];
	}

	if (sum % x) {
		cout << n << "\n";
		return;
	}

	int left = 0, right = n - 1;
	while (left < n && nums[left] % x == 0) ++left;
	while (right >= 0 && nums[right] % x == 0) --right;

	if (left == n || right == -1) cout << -1 << "\n";
	else cout << n - min(left + 1, n - right) << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}