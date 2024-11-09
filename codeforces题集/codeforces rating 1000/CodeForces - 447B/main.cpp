#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void Test() {
	string s;
	cin >> s;
	int k = 0;
	cin >> k;

	vector<int> nums(26);
	int mx = 0;
	for (int i = 0; i < 26; i++) {
		cin >> nums[i];
		mx = max(mx, nums[i]);
	}

	int ans = 0;
	for (int i = 1; i <= s.size(); i++) {
		ans += nums[s[i - 1] - 'a'] * i;
	}
	for (int i = s.size() + 1; i <= s.size() + k; i++) {
		ans += mx * i;
	}
	cout << ans << "\n";
}

int main() {
	Test();
	return 0;
}