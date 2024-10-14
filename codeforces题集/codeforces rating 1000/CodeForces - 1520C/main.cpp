#include <iostream>
using namespace std;

//1 3 5 7
//9 11 13 15
//2 4 6 8
//10 12 14 16
void Test() {
	int n = 0;
	cin >> n;
	if (n == 1) cout << 1 << endl;
	else if (n == 2) cout << -1 << endl;
	else {
		int index = 0;
		for (int i = 1; i <= n * n; i += 2) {
			cout << i << " ";
			++index;
			if (index == n) {
				index = 0;
				cout << "\n";
			}
		}

		for (int i = 2; i <= n * n; i += 2) {
			cout << i << " ";
			++index;
			if (index == n) {
				index = 0;
				cout << "\n";
			}
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