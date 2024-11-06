#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());
	int begin = 1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] >= begin) {
			++ans;
			++begin;
		}
	}
	cout << ans << "\n";
}

int main() {
	Test();
	return 0;
}