#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;

//思路是二分答案，我真的是完全没有想到呢
void Test() {
	ll n = 0, x = 0;
	cin >> n >> x;

	vector<ll> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	ll left = 1, right = 2e9 + 1, ans = -1;
	while (left < right) {
		ll mid = (left + right) / 2;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid > nums[i]) sum += mid - nums[i];
		}
		if (sum > x) right = mid;
		else {
			ans = mid;
			left = mid + 1;
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