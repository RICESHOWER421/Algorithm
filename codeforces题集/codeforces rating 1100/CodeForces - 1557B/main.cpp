#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

void Test() {
	int n = 0, k = 0;
	cin >> n >> k;

	vector<int> nums(n), copy;
	map<int, int> hash_map;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		hash_map[nums[i]] = i;
	}

	copy = nums;
	sort(copy.begin(), copy.end());
	int count = 0;
	vector<bool> vis(n);
	for (int i = 0; i < n;) {
		if (!vis[i]) {
			vis[i] = true;
			bool ok = true;
			int index = hash_map[copy[i]];
			while (ok) {
				if (index + 1 < n && i + 1 < n && nums[index + 1] == copy[i + 1]) {
					++index;
					++i;
					vis[i] = true;
				}
				else {
					++count;
					ok = false;
				}
			}
		}
		else ++i;
	}

	if (count > k) {
		cout << "NO" << "\n";
	}
	else {
		cout << "YES" << "\n";
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