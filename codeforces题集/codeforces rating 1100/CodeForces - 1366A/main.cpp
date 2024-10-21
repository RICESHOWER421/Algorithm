#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void Test() {
	int a = 0, b = 0;
	cin >> a >> b;
	if (a < b) swap(a, b);
	
	if (a >= 2 * b) cout << b << "\n";
	else {
		int ret = b - (a - b);
		cout << a - b + (ret / 3) * 2 + (ret % 3 == 2) << "\n";
	}
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}