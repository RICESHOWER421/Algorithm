#include <iostream>
using namespace std;

//100
//111
void Test() {
	int n = 0;
	cin >> n;
	int t = 1;
	while (t < n) t *= 2;
	t /= 2;

	for (int i = 1; i < t; i++) {
		cout << i << " ";
	}
	cout << 0 << " ";
	for (int i = t; i < n; i++) {
		cout << i << " ";
	}
	cout << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}