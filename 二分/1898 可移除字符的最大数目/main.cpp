#include <bits/stdc++.h>
using namespace std;

bool hash_map[100010];
class Solution {
public:
	int maximumRemovals(string s, string p, vector<int>& removable) {
		int l = 0, r = removable.size(), n = s.size(), m = p.size();
		auto check = [&](int mid)->bool {
			string tmp;
			memset(hash_map, false, sizeof(hash_map));
			for (int i = 0; i < mid; i++) {
				hash_map[removable[i]] = true;
			}

			for (int i = 0; i < n; i++) {
				if (!hash_map[i]) {
					tmp += s[i];
				}
			}

			int l = 0, r = 0;
			while (l < tmp.size() && r < m) {
				if (tmp[l] == p[r]) {
					++r;
				}
				++l;
			}
			return r == m;
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