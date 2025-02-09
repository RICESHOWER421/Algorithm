#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void Test() {
	ll l = 0, r = 0;
	cin >> l >> r;
	cout << "YES" << "\n";
	for(ll i = l; i <= r; i += 2) {
		cout << i << " " << i + 1 << "\n";
	}
}

int main() {
	Test();
	return 0;
}