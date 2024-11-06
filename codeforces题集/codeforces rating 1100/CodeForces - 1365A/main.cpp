#include <iostream>
#include <vector>
using namespace std;

void Test() {
	int n = 0, m = 0;
	cin >> n >> m;
	
	int ret_1 = 0, ret_2 = 0;
	vector<int> rows(n), cols(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num = 0;
			cin >> num;
			rows[i] += num;
			cols[j] += num;
			if (i == n - 1) {
				if (!cols[j]) ++ret_2;
			}
		}
		if (!rows[i]) ++ret_1;
	}

	if (min(ret_1, ret_2) % 2) cout << "Ashish" << "\n";
	else cout << "Vivek" << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}