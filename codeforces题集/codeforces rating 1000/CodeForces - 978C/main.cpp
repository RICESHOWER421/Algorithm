#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

void Test() {
	ll n = 0, m = 0;
	cin >> n >> m;

	vector<ll> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];
	
	vector<ll> dp(n + 1);
	for (int i = 1; i <= n; i++) dp[i] = dp[i - 1] + nums[i - 1];

	int cur = 0;
	for (int i = 0; i < m; i++) {
		ll num = 0;
		cin >> num;
		while (num > dp[cur]) {
			++cur;
		}
		cout << cur << " " << num - dp[cur - 1] << "\n";
	}
}

int main() {
	Test();
	return 0;
}