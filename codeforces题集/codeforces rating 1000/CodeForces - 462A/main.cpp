#include <bits/stdc++.h>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	vector<string> ret(n);

	for (int i = 0; i < n; i++) {
		cin >> ret[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			if (i - 1 >= 0 && ret[i - 1][j] == 'o') ++cnt;
			if (i + 1 < n && ret[i + 1][j] == 'o') ++cnt;
			if (j - 1 >= 0 && ret[i][j - 1] == 'o') ++cnt;
			if (j + 1 < n && ret[i][j + 1] == 'o') ++cnt;

			if (cnt % 2) {
				cout << "NO" << "\n";
				return;
			}
		}
	}
	cout << "YES" << "\n";
}

int main() {
	Test();
	return 0;
}