#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;

	int max_1 = 0, sum_1 = 0;
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		sum_1 += num;
		max_1 = max(max_1, sum_1);
	}

	int m = 0;
	cin >> m;
	int max_2 = 0, sum_2 = 0;
	for (int i = 0; i < m; i++) {
		int num = 0;
		cin >> num;
		sum_2 += num;
		max_2 = max(max_2, sum_2);
	}

	cout << max_1 + max_2 << endl;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}