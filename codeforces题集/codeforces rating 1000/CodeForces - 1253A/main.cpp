#include <iostream>
#include <vector>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		nums[i] = num - nums[i];
	}

	bool ok = true;
	int tmp = -1;
	for (int i = 0; i < n; i++) {
		if (nums[i] < 0) {
			cout << "NO" << "\n";
			return;
		}
		else {
			if (nums[i]) {
				if (ok) {
					if (tmp == -1) tmp = nums[i];
					else {
						if (tmp != nums[i]) {
							cout << "NO" << "\n";
							return;
						}
					}
				}
				else {
					cout << "NO" << "\n";
					return;
				}
			}
			else {
				if (tmp != -1) ok = false;
			}
		}
	}
	cout << "YES" << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}