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

	int k = 0;
	for (int i = 0; i < n - 2; i++) {
		if (nums[i] == 1 && nums[i + 1] == 0 && nums[i + 2] == 1){
			++k;
			nums[i + 2] = 0;
		}
	}
	cout << k << "\n";
}

int main() {
	Test();
	return 0;
}