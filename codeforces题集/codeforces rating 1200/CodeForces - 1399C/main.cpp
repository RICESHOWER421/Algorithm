#include <iostream>
#include <vector>
#include <map>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	vector<int> nums(n), ret, sums;
	vector<int> hash_map(51);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		if (!hash_map[nums[i]]) ret.push_back(nums[i]);
		hash_map[nums[i]]++;
	}

	if (n == 1) {
		cout << 0 << "\n";
		return;
	}

	for (int i = 0; i < ret.size(); i++) {
		for (int j = i; j < ret.size(); j++) {
			sums.push_back(ret[i] + ret[j]);
		}
	}

	int mx = 1;
	for (int i = 0; i < sums.size(); i++) {
		int count = 0, tmp = 0;
		for (int j = 0; j < ret.size(); j++) {
			if (sums[i] - ret[j] >= 1 && sums[i] - ret[j] <= 50 && hash_map[sums[i] - ret[j]]) {
				if (ret[j] == sums[i] - ret[j]) tmp += hash_map[ret[j]] / 2;
				else count += min(hash_map[ret[j]], hash_map[sums[i] - ret[j]]);
			}
		}
		mx = max(tmp + count / 2, mx);
	}
	cout << mx << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}