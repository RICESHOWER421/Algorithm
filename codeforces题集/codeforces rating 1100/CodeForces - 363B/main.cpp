#include <iostream>
#include <vector>
using namespace std;

void Test() {
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];

	int sum = 0;
	int left = 0, right = 0;
	while (right - left < k) {
		sum += nums[right];
		++right;
	}

	int min_num = sum, index = left;
	while (right < n) {
		sum += nums[right];
		sum -= nums[left];
		++left;
		if (sum < min_num) {
			min_num = sum;
			index = left;
		}
		++right;
	}
	cout << index + 1 << endl;
}

int main() {
	Test();
	return 0;
}