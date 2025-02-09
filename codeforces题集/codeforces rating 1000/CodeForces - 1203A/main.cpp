#include <bits/stdc++.h>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	if (n == 1) {
		cout << "YES" << "\n";
		return;
	}

	int pos = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] == 1) {
			pos = i;
			break;
		}
	}

	int num = 1, ret = n;
	if (nums[pos - 1 >= 0 ? pos - 1 : n - 1] == 2) {
		while (n--) {
			if (nums[pos] == num) {
				pos--;
				++num;
			}
			else {
				cout << "NO" << "\n";
				return;
			}

			if (pos == -1) {
				pos = ret - 1;
			}
		}
		cout << "YES" << "\n";
	}
	else if (nums[pos + 1 < n ? pos + 1 : 0] == 2) {
		while (n--) {
			if (nums[pos] == num) {
				pos++;
				++num;
			}
			else {
				cout << "NO" << "\n";
				return;
			}

			if (pos == ret) {
				pos = 0;
			}
		}
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}
}

int main() {
	int n = 0;
	cin >> n;
	while (n--) {
		Test();
	}
	return 0;
}
