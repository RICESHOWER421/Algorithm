#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void Test() {
	int n = 0, c = 0;
	cin >> n >> c;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		ans = max(ans, nums[i] - nums[i + 1] - c);
	}
	cout << ans << "\n";
}

int main() {
	Test();
	return 0;
}