#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Test() {
	int s = 0, n = 0;
	cin >> s >> n;
	
	vector<pair<int, int>> nums;
	while (n--) {
		int x = 0, y = 0;
		cin >> x >> y;
		nums.push_back({ x,y });
	}

	sort(nums.begin(), nums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.first < b.first;
	});

	for (int i = 0; i < (int)nums.size(); i++) {
		if (s > nums[i].first) s += nums[i].second;
		else {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main() {
	Test();
	return 0;
}