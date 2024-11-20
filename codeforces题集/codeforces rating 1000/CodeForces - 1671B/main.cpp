#include <iostream>
#include <vector>
using namespace std;

//1 2 3 5 6 7 9 10 11 13 14 15
//
void Test() {
	int n = 0;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	bool ok = true;
	int ret1 = 0, ret2 = 0;
	for (int i = 1; i < n; i++) {
		if (nums[i] - nums[i - 1] > 3) {
			ok = false;
			break;
		}
		else {
			if (nums[i] - nums[i - 1] == 3) {
				if (!ret1 && !ret2) {
					++ret2;
				}
				else {
					ok = false;
					break;
				}
			}
			else if (nums[i] - nums[i - 1] == 2) {
				if (!ret2 && ret1 < 2) {
					++ret1;
				}
				else {
					ok = false;
					break;
				}
			}
		}
	}

	if (ok) cout << "YES" << "\n";
	else cout << "NO" << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}