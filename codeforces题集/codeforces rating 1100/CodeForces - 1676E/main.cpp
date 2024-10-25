#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <deque>
#include <queue>
#include <list>
typedef long long ll;
using namespace std;

void Test() {
	int n = 0, q = 0;
	cin >> n >> q;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];

	sort(nums.begin(), nums.end(), greater<int>());
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++) dp[i] = dp[i - 1] + nums[i - 1];

	while (q--) {
		int num = 0;
		cin >> num;

		int index = 1;
		int temp = 0;
		int left = 1, right = n, mid = 0;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (dp[mid] > num) right = mid;
			else if (dp[mid] < num) left = mid + 1;
			else {
				left = mid;
				break;
			}
		}

		if (left == n && dp[n] < num) cout << -1 << endl;
		else cout << left << endl;
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