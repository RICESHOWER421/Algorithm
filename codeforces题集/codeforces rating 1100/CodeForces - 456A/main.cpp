#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

//复杂写法，主要还是想复杂了
//void Test() {
//	int n = 0;
//	cin >> n;
//	map<int, pair<int, int>> hash_map;
//
//	vector<int> ps;
//	for (int i = 0; i < n; i++) {
//		int num = 0, m = 0;
//		cin >> num >> m;
//		if (!hash_map.count(num)) {
//			ps.push_back(num);
//			hash_map[num].first = hash_map[num].second = m;
//		}
//		else {
//			hash_map[num].first = min(hash_map[num].first, m);
//			hash_map[num].second = max(hash_map[num].second, m);
//		}
//	}
//
//	sort(ps.begin(), ps.end());
//	int s = ps.size();
//	vector<int> nums(s);
//	for (int i = s - 1; i >= 1; i--) {
//		if (i == s - 1) nums[i] = hash_map[ps[i]].first;
//		else nums[i] = min(hash_map[ps[i]].first, nums[i + 1]);
//	}
//
//	for (int i = 0; i < s - 1; i++) {
//		if (hash_map[ps[i]].second > nums[i + 1]) {
//			cout << "Happy Alex" << "\n";
//			return;
// 		}
//	}
//	cout << "Poor Alex" << "\n";
//}

void Test() {
	int n = 0;
	cin >> n;
	vector<pair<int, int>> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i].first >> nums[i].second;
	}

	sort(nums.begin(), nums.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first == b.first) return a.second < b.second;
		else return a.first < b.first;
	});

	for (int i = 0; i < n - 1; i++) {
		if (nums[i].first != nums[i + 1].first) {
			if (nums[i].second > nums[i + 1].second) {
				cout << "Happy Alex" << "\n";
				return;
			}
		}
	}
	cout << "Poor Alex" << "\n";
}

int main() {
	Test();
	return 0;
}