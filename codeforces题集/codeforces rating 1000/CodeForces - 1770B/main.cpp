#include <iostream>
#include <vector>
using namespace std;

void Test() {
	int n = 0, k = 0;
	cin >> n >> k;
	
	int ret1 = n, ret2 = 1;
	for (int i = 0; i < k - 1; i++) {
		cout << ret1 << " ";
		--ret1;
	}

	for (int i = k - 1; i < 2 * (k - 1) && i < n; i++) {
		cout << ret2 << " ";
		++ret2;
	}

	if (ret1 >= ret2) {
		for (int i = 2 * (k - 1); i < n; i += 2) {
			if (ret1 == ret2) cout << ret1 << " ";
			else cout << ret1 << " " << ret2 << " ";
			--ret1;
			++ret2;
		}
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