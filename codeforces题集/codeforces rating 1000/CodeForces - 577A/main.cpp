#include <iostream>
#include <cmath>
using namespace std;

void Test() {
	int n = 0, k = 0;
	cin >> n >> k;

	int ret = sqrt(k);
	int ans = 0;
	for (int i = 1; i <= ret && i <= n; i++) {
		if (k % i == 0) {
			if (k / i <= n && i != k / i) ans += 2;
			else if (k / i <= n && i == k / i) ++ans;
		}
	}
	cout << ans << endl;
}

int main() {
	Test();
	return 0;
}