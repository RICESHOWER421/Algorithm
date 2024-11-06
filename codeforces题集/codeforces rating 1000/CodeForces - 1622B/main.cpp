#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	string s;
	cin >> s;

	vector<int> less, more;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			less.push_back(nums[i]);
		}
		else {
			more.push_back(nums[i]);
		}
	}

	sort(less.begin(), less.end());
	sort(more.begin(), more.end());
	map<int, int> hash_map;

	int begin = 1;
	for (int i = 0; i < less.size(); i++) {
		hash_map[less[i]] = begin;
		++begin;
	}

	for (int i = 0; i < more.size(); i++) {
		hash_map[more[i]] = begin;
		++begin;
	}
	
	for (auto& x : nums) {
		cout << hash_map[x] << " ";
	}
	cout << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}