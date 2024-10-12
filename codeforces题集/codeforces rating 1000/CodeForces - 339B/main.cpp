#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

void Test() {
	int n = 0, m = 0;
	cin >> n >> m;

	vector<int> nums(m);
	for (int i = 0; i < m; i++) {
		cin >> nums[i];
	}

	ll ans = nums[0];
	for (int i = 1; i < m; i++) {
		if (nums[i] > nums[i - 1]) {
			ans += nums[i] - nums[i - 1];
		}
		else if (nums[i] == nums[i - 1]) continue;
		else {
			ans += (n - nums[i - 1] + nums[i]);
		}
	}
	cout << ans  - 1 << endl;
}

int main() {
	Test();
	return 0;
}