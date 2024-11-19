#include <iostream>
#include <vector>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int left = 0, right = n - 1;
	int ls = 0, rs = 0, ans = 0;
	while (left <= right) {
		if (ls + nums[left] < rs + nums[right]) {
			ls += nums[left];
			++left;
			if (ls == rs) ans = max(ans, left + n - right - 1);
		}
		else {
			rs += nums[right];
			--right;
			if (ls == rs) ans = max(ans, left + n - right - 1);
		}
	}
	cout << ans << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}