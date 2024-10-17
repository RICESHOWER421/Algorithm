#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;

void Test() {
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<ll> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];

	ll count = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] <= k) ++count;
		else {
			if (count >= m) {
				ll ret = count - m + 1;
				ans += ret * (1 + ret) / 2;
			}
			count = 0;
		}
	}
	cout << ans + (count >= m ? (count - m + 1) * (1 + count - m + 1) / 2 : 0) << endl;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}