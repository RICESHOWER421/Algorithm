#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Test() {
	int n = 0, m = 0, x = 0, y = 0;
	cin >> n >> m >> x >> y;
	vector<string> grids(n);
	int two = min(2 * x, y);
	
	for (int i = 0; i < n; i++) cin >> grids[i];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int ret = 0;
		for (int j = 0; j < m; j++) {
			if (grids[i][j] == '*') {
				ans += (ret / 2) * two + (ret % 2) * x;
				ret = 0;
			}
			else ++ret;
		}
		ans += (ret / 2) * two + (ret % 2) * x;
	}
	cout << ans << endl;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}