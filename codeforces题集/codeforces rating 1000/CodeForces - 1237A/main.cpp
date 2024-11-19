#include <iostream>
#include <vector>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	vector<int> nums(n);

	int ret = 0;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		if (nums[i] % 2 == 0) ++ret;
	}

	int half = (n - ret) / 2;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] % 2 == 0) {
			cout << nums[i] / 2 << "\n";
		}
		else {
			if (count < half) {
				if (nums[i] > 0) cout << nums[i] / 2 << "\n";
				else cout << nums[i] / 2 - 1 << "\n";
				++count;
 			}
			else {
				if (nums[i] > 0) cout << nums[i] / 2 + 1 << "\n";
				else cout << nums[i] / 2 << "\n";
			}
		}
	}
}

int main() {
	Test();
	return 0;
}