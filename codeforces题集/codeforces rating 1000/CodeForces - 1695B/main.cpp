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

	if (n % 2) cout << "Mike" << "\n";
	else {
		int mn = nums[0], index = 0;
		for (int i = 0; i < n; i++) {	//不能想的太简单，主要思路还是一点一点消耗
			if (nums[i] < mn) {
				mn = nums[i];
				index = i;
			}
		}

		if ((index + 1) % 2) cout << "Joe" << "\n";
		else cout << "Mike" << "\n";
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