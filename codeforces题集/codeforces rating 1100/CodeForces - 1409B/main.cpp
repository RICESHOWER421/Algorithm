#include <iostream>
typedef long long ll;
using namespace std;

void Test() {
	ll a = 0, b = 0, x = 0, y = 0, n = 0;
	cin >> a >> b >> x >> y >> n;
	

	ll c = max(x, a - n), d = max(y, b - n);
	if (c <= d) {
		cout << c * max(y, (b - (n - (a - c)))) << "\n";
	}
	else {
		cout << d * max(x, (a - (n - (b - d)))) << "\n";
	}
}

//
int main() {
	int t = 0;
	cin >> t;
	while(t--) {
		Test();
	}
	return 0;
}