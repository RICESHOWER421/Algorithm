#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	vector<ll> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	ll ans = 0;
	ll mx_1 = nums[0] > 0 ? nums[0] : INT_MIN, mx_2 = nums[0] < 0 ? nums[0] : INT_MIN;
	for (int i = 1; i < n; i++) {
		if (nums[i] > 0 && nums[i - 1] > 0) mx_1 = max(mx_1, nums[i]);
		else if (nums[i] < 0 && nums[i - 1] < 0) mx_2 = max(mx_2, nums[i]);
		else {
			if (nums[i - 1] > 0) {
				ans += mx_1;
				mx_1 = INT_MIN;
				mx_2 = max(mx_2, nums[i]);
			}
			else {
				ans += mx_2;
				mx_2 = INT_MIN;
				mx_1 = max(mx_1, nums[i]);
			}
		}
	}
	cout << ans + (mx_1 == INT_MIN ? mx_2 : mx_1) << "\n";
}
int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}