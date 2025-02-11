#include <bits/stdc++.h>
using namespace std;

void Test() {
	string a, b;
	cin >> a >> b;

	if (a == b) {
		cout << "YES" << "\n";
		cout << a << "\n";
		return; 
 	}

	if (a[0] == b[0]) {
		cout << "YES" << "\n";
		cout << b[0] << "*" << "\n";
	} 
	else if (a.back() == b.back()) {
		cout << "YES" << "\n";
		cout << "*" << b.back() << "\n";
	}
	else {
		map<string, bool> hash_map;
		if (b.size() >= 2) {
			for (int i = 0; i < b.size() - 1; i++) {
				hash_map[b.substr(i, 2)] = true;
			}
		}

		for (int i = 0; i < a.size() - 1; i++) {
			if (hash_map.count(a.substr(i, 2))) {
				cout << "YES" << "\n";
				cout << "*" << a.substr(i, 2) << "*" << "\n";
				return;
			}
		}
		cout << "NO" << "\n";
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