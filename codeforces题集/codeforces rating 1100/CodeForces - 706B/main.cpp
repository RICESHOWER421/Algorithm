#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];
	sort(nums.begin(), nums.end());

	int m = 0;
	cin >> m;
	while (m--) {
		int num = 0;
		cin >> num;
		int left = 0, right = n;
		while (left < right) {
			int mid = (left + right) / 2;
			if (nums[mid] < num + 1) left = mid + 1;
			else right = mid;
		}
		cout << left << "\n";
	}
}
int main() {
	Test();
	return 0;
}