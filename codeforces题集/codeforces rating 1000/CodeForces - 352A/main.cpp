#include <iostream>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;

	int ret_0 = 0, ret_1 = 0;
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		if (num == 5) ++ret_1;
		else ++ret_0;
	}

	int ans = ret_1 / 9;
	if (ans && ret_0) {
		for (int i = 0; i < ans; i++) cout << "555555555";
		for (int i = 0; i < ret_0; i++) cout << "0";
		cout << "\n";
	}
	else {
		if (ret_0) cout << 0 << "\n";
		else cout << -1 << "\n";
	}
}

int main() {
	Test();
	return 0;
}