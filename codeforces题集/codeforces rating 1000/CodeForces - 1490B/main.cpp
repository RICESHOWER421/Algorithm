#include <iostream>
#include <vector>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;

	vector<int> nums(3);
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		nums[num % 3]++;
	}

	int ans = 0;
	vector<int> more;
	for (int i = 0; i < 3; i++) {
		if (nums[i] > n / 3) more.push_back(i);
	}

	if (more.size() == 0) cout << 0 << endl;
	else if (more.size() == 1) cout << n / 3 - nums[(more[0] + 1) % 3] + (n / 3 - nums[(more[0] + 2) % 3]) * 2 << endl;
	else {
		int pos = -1;
		for (int i = 0; i < 3; i++) {
			if (nums[i] < n / 3) pos = i;
		}
		cout << (nums[(pos + 1) % 3] - n / 3) * 2 + nums[(pos + 2) % 3] - n / 3 << endl;
	}
}
int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}