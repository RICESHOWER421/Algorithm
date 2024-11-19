#include <iostream>
using namespace std;
typedef long long ll;

void Test() {
	ll n = 0;
	cin >> n;

	ll left = 1, right = 1e9;
	while (left < right) {
		ll mid = (left + right) / 2;
		if (mid * mid < n) left = mid + 1;
		else right = mid;
	}
	cout << right - 1 << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}