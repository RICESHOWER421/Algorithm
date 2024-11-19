#include <iostream>
#include <vector>
#include <map>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	map<int, int> hash_map;
	for (auto& x : nums) {
		if (!hash_map.count(x)) hash_map[x] = 1;
		else {
			cout << "YES" << "\n";
			return;
		}
	}
	cout << "NO" << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}