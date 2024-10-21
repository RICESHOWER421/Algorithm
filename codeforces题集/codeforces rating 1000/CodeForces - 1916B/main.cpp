#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

int gcd(ll a, ll b) {
	while (a % b) {
		ll temp = a % b;
		a = b;
		b = temp;
	}
	return b;
}

void Test() {
	ll a = 0, b = 0;
	cin >> a >> b;
	if (a == 1 || b == 1) cout << max(a, b) * max(a, b) << "\n";
	else{
		if (a > b) swap(a, b);

		if (gcd(a, b) == 1) {
			cout << a * b << "\n";
		}
		else if(gcd(a, b) == a){
			cout << b * (b / a) << "\n";
		}
		else {
			cout << b * a / gcd(a, b) << "\n";
		}
	}
}

int main() {
	int t = 0;
	cin >> t;
	while (t--) {
		Test();
	}
	return 0;
}