#include <iostream>
#include <vector>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];
	for (int i = 0; i < n - 2; i++) {
		if (nums[i] < 0) {
			cout << "NO" << endl;
			return;
		}
		else {
			nums[i + 1] -= nums[i] * 2;
			nums[i + 2] -= nums[i];
			nums[i] = 0;
		}
	}

	if (nums[n - 1] == 0 && nums[n - 2] == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}