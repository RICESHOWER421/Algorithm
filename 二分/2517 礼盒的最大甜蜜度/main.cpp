#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class Solution {
public:
	int maximumTastiness(vector<int>& price, int k) {
		int n = price.size(), l = 0, r = 0;
		sort(price.begin(), price.end());
		r = price.back();
		auto check = [&](int pos)->bool {
			int cnt = 1, tmp = price[0];
			for (int i = 1; i < n; i++) {
				if (price[i] - tmp >= pos) {
					++cnt;
					tmp = price[i];
				}
				if (cnt == k) return true;
			}
			return false;
		};

		while (l < r) {
			int mid = l + (r - l + 1) / 2;
			if (check(mid)) l = mid;
			else r = mid - 1;
		}
		return l;
	}
};

int main() {

	return 0;
}