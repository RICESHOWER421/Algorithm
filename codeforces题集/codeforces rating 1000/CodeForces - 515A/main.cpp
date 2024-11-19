#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

void Test() {
	ll a = 0, b = 0, s = 0;
	cin >> a >> b >> s;
	ll sum = abs(a) + abs(b);
	if (sum > s) {
		cout << "NO" << "\n";
	}
	else {
		if ((s - sum) % 2 == 0) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
}

int main() {
	Test();
	return 0;
}