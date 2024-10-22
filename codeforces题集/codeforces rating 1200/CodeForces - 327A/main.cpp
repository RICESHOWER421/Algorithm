#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//一开始完全想错了，思维题目还得练
void Test() {
	int n = 0;
	cin >> n;
	vector<int> nums(n);
	int ret = 0;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		if (nums[i] == 1) ++ret;
	}

	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int ret_0 = 0, ret_1 = 0;
			for (int k = i; k <= j; k++) {
				if (nums[k]) ++ret_1;
				else ++ret_0;
			}
			mx = max(mx, ret - ret_1 + ret_0);
		}
	}
	cout << mx << "\n";
	
}

int main() {
	Test();
	return 0;
}