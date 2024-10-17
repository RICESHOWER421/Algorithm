#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end(), greater<int>());
	for (int i = 0; i < n; i++) cout << nums[i] << " ";
	cout << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}