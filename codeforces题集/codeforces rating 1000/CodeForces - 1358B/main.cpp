#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1 1 4 5 5 9
void Test() {
	int n = 0;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());

	int ans = 0;
	int left = 0, right = 1;	//left表示已经有的老奶奶数，right表示叫到的老奶奶数
	while (right <= n && left < n) {
		if (right >= nums[left]) {
			if (left == right) ++right;
			++left;
		}
		else ++right;
		if (left == right) ans = left;
	}
	cout << ans + 1 << endl;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}