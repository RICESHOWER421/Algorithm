#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

//5 4 3 2 1 2 3 4 5 
void Test() {
	int n = 0;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	
	bool ok = true;
	for (int i = 1; i < n; i++) {
		if (ok) {
			if (nums[i] < nums[i - 1]) {
				ok = false;
			}
		}
		else {
			if (nums[i] > nums[i - 1]) {
				cout << "NO" << "\n";
				return;
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