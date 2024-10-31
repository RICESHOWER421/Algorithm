#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	vector<ll> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	ll ret = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] > 0) ret += nums[i];
		else {
			if (ret > abs(nums[i])) {
				ret -= abs(nums[i]);
				nums[i] = 0;
			}
			else {
				nums[i] += ret;
				ret = 0;
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] < 0) ans += abs(nums[i]);
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