#include <iostream>
using namespace std;
typedef long long ll;

void Test() {
	ll n = 0;
	cin >> n;

	ll ans = 0;
	ll index = 1;
	for (int i = 3; i <= n; i += 2) {
		ans += (4 * i - 4) * index;
		++index;
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