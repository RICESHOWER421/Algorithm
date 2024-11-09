#include <iostream>
using namespace std;

void Test() {
	int a = 0, b = 0;
	cin >> a >> b;
	if (a >= b) {
		cout << "YES" << "\n";
	}
	else {
		if (a == 1 || a == 3 || a == 2 && b != 3) {
			cout << "NO" << "\n";
		}
		else {
			cout << "YES" << "\n";
		}
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