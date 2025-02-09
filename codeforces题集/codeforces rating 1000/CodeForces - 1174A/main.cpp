#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;

	vector<int> nums(2 * n);
	for (int i = 0; i < 2 * n; i++) cin >> nums[i];
	sort(nums.begin(), nums.end());

	bool ok = false;
	for (auto& x : nums) {
		if (x != nums[0]) {
			ok = true;
			break;
		}
	}

	if (ok) {
		for (auto& x : nums) {
			cout << x << " ";
		}
		cout << "\n";
	}
	else cout << -1 << "\n";
}
int main() {
	Test();
	return 0;
}