#include <iostream>
#include <vector>
using namespace std;

//2 5 1 4 3
void Test() {
	int n = 0;
	cin >> n;

	vector<int> nums(n);
	int left = 0, right = n - 1;
	int num = 2;
	while (left <= right) {
		if (left == right) nums[left] = 1;
		else if (left == right - 1) {
			nums[left] = 1;
			nums[right] = num;
		}
		else {
			nums[left] = num;
			nums[right] = num + 1;
		}
		++left;
		--right;
		num += 2;
	}

	for (auto& x : nums) cout << x << " ";
	cout << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--){
		Test();
	}
	return 0;
}