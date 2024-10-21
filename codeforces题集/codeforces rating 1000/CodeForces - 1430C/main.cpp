#include <iostream>
using namespace std;



void Test() {
	int n = 0;
	cin >> n;

	cout << 2 << "\n";
	cout << n - 1 << " " << n << "\n";
	while (n - 2) {
		cout << n - 2 << " " << n << "\n";
		--n;
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