#include <iostream>
using namespace std;

void Test() {
	int n = 0, k = 0;
	cin >> n >> k;

	if (k == 1) {
		cout << "YES" << "\n";
		for (int i = 1; i <= n; i++) {
			cout << i << "\n";
		}
	}
	else {
		if (n % 2) cout << "NO" << "\n";
		else {
			cout << "YES" << "\n";
			int count = 0;
			for (int i = 1; i <= n * k; i += 2) {
				cout << i << " ";
				++count;
				if (count == k) {
					cout << "\n";
					count = 0;
				}
			}

			for (int i = 2; i <= n * k; i += 2) {
				cout << i << " ";
				++count;
				if (count == k) {
					cout << "\n";
					count = 0;
				}
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