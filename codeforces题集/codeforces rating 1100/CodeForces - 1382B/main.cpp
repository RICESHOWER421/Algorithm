#include <iostream>
#include <vector>
using namespace std;

//1 2 2 1 2 1
void Test() {
	int n = 0;
	cin >> n;

	bool ok = true;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		if (num == 1) {
			if (ok) ++ret;
		}
		else {
			ok = false;
		}
	}

	if (ret == n) {
		if (ret % 2) {
			cout << "First" << "\n";
		}
		else {
			cout << "Second" << "\n";
		}
	}
	else {
		if (ret % 2) {
			cout << "Second" << "\n";
		}
		else {
			cout << "First" << "\n";
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