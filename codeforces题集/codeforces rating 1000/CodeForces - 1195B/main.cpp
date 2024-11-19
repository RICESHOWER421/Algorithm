#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

void Test() {
	ll n = 0, k = 0;
	cin >> n >> k;
	ll ans1 = (3 + 2 * n + sqrt(8 * n + 8 * k + 9)) / 2, ans2 = (3 + 2 * n - sqrt(8 * n + 8 * k + 9)) / 2;
	if (ans1 >= 0 && ans1 <= n) {
		cout << ans1 << "\n";
	}
	else {
		cout << ans2 << "\n";
	}
}

int main() {
	Test();
	return 0;
}