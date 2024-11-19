#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

void Test() {
	ll w = 0, k = 0;
	cin >> w >> k;

	int n1 = 0;
	cin >> n1;
	ll ans1 = 0;
	for (int i = 0; i < n1; i++) {
		ll num = 0;
		cin >> num;
		if (i == 0) ans1 -= num;
		if (i == n1 - 1) ans1 += num;
	}

	int n2 = 0;
	cin >> n2;
	ll ans2 = 0;
	for (int i = 0; i < n2; i++) {
		ll num = 0;
		cin >> num;
		if (i == 0) ans2 -= num;
		if (i == n2 - 1) ans2 += num;
	}

	int n3 = 0;
	cin >> n3;
	ll ans3 = 0;
	for (int i = 0; i < n3; i++) {
		ll num = 0;
		cin >> num;
		if (i == 0) ans3 -= num;
		if (i == n3 - 1) ans3 += num;
	}

	int n4 = 0;
	cin >> n4;
	ll ans4 = 0;
	for (int i = 0; i < n4; i++) {
		ll num = 0;
		cin >> num;
		if (i == 0) ans4 -= num;
		if (i == n4 - 1) ans4 += num;
	}

	cout << max(ans1 * k, max(ans2 * k, max(ans3 * w, ans4 * w))) << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}