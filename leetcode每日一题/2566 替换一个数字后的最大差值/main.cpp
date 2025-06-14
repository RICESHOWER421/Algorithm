#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class Solution {
public:
	int minMaxDifference(int num) {
		string tmp = to_string(num);
		int mx = -1, mn = 0x3f3f3f3f;
		for (char i = '0'; i <= '9'; i++) {
			for (char j = '0'; j <= '9'; j++) {
				if (i == j) continue;
				string ret = tmp;
				for (int k = 0; k < ret.size(); k++) {
					if (ret[k] == i) ret[k] = j;
				}
				int num = atoi(ret.c_str());
				mx = max(mx, num);
				mn = min(mn, num);
			}
		}
		return mx - mn;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
}
