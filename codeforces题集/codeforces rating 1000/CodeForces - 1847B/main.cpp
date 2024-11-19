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

	int left = 0, right = 0, ret = 0, count = 0;
	while (right < nums.size()){
		if (left == right) {
			ret = nums[left];
			if (ret == 0) {
				left = right + 1;
				++count;
			}
		}
		else {
			ret &= nums[right];
			if (ret == 0) {
				left = right + 1;
				++count;
			}
		}
		++right;
	}
	cout << (count == 0 ? 1 : count) << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}