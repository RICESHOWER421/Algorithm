#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void Test() {
	string a, b;
	cin >> a >> b;

	int ret1 = 0;
	for (auto& x : a) {
		if (x == 'a') ++ret1;
	}

	if (ret1 == 0) {
		cout << 1 << "\n";
		return;
	}

	int ret2 = 0;
	for (auto& x : b) {
		if (x == 'a') ++ret2;
	}

	if (ret2 == 1 && b.size() == 1) {
		cout << 1 << "\n";
	}
	else if (ret2 == 0) {
		cout << (long long)pow(2, ret1) << "\n";
	}
	else {
		cout << -1 << "\n";
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