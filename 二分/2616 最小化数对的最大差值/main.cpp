#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class Solution {
public:
	int minimizeMax(vector<int>& nums, int p) {
		if (p == 0) return 0;
		int n = nums.size(), l = 0, r = 0;
		for (auto& x : nums) {
			r = max(x, r);
		}
		sort(nums.begin(), nums.end());

		auto check = [&](int mid)->bool {
			int cnt = 0;
			for (int i = 1; i < n;) {
				if (nums[i] - nums[i - 1] <= mid) {
					++cnt;
					i += 2;
				}
				else {
					++i;
				}
				if (cnt == p) return true;
			}
			return false;
		};

		while (l < r) {
			int mid = l + (r - l) / 2;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		return l;
	}
};

//1 1 2 3 7 10
int main() {
	vector<int> nums = { 1,1,2,3,7,10 };
	int p = 0;
	cout << Solution().minimizeMax(nums, p) << "\n";
	return 0;
}