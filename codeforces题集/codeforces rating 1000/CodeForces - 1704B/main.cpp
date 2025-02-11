#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void Test() {
	ll n = 0, x = 0;
	cin >> n >> x;
	vector<ll> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	ll mn = INT_MAX, mx = -1, ans = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] < mn) {
			mn = nums[i];
		}
		if (nums[i] > mx) {
			mx = nums[i];
		}

		if (mx - mn > 2 * x) {
			++ans;
			mx = mn = nums[i];
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
