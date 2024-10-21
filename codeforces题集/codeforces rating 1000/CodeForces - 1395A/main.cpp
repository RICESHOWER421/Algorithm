#include <iostream>
#include <cmath>
using namespace std;

void Test() {
	int a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;
	
	int ret = 0;
	if (a % 2) ++ret;
	if (b % 2) ++ret;
	if (c % 2) ++ret;
	
	int mn = min(a, min(b,c));
	if (ret == 0 || ret == 3) {
		cout << "Yes" << "\n";
	}
	else if (ret == 1) {
		if (d % 2 == 0) {
			cout << "Yes" << "\n";
		}
		else {
			cout << "No" << "\n";
		}
	}
	else {
		if (d % 2 && mn) {
			cout << "Yes" << "\n";
		}
		else {
			cout << "No" << "\n";
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