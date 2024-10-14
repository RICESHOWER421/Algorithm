#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

void Test() {
	ll x = 0, y = 0;
	cin >> x >> y;
	ll a = 0, b = 0;
	cin >> a >> b;

	ll ans_1 = (x + y) * a;
	ll ans_2 = min(x, y) * b + abs(x - y) * a;
	cout << min(ans_1, ans_2) << endl;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}