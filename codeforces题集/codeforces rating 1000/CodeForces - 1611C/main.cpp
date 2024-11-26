#include <iostream>
#include <vector>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];
	if (nums[0] != n && nums.back() != n) cout << -1 << "\n";
	else {
		if (nums[0] == n) {
			cout << nums[0] << " ";
			for (int i = n - 1; i >= 1; i--) {
				cout << nums[i] << " ";
			}
			cout << "\n";
		}
		else {
			cout << nums.back() << " ";
			for (int i = n - 2; i >= 0; i--) {
				cout << nums[i] << " ";
			}
			cout << "\n";
		}
	}
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}