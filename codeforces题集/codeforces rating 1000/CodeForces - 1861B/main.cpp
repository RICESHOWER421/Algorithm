#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

//0110110011
void Test() {
	string a, b;
	cin >> a >> b;
	if (a[0] == b[0] && a[0] == a.back() && a[0] == b.back()) {
		cout << "YES" << "\n";
	}
	else if (a[0] == b[0] && a.back() == b.back()) {
		map<int, int> hash_map;
		vector<int> ret;
		for (int i = 0; i < a.size(); i++) {
			if (a[0] == '0') {
				if (a[i] == b[i] && a[i] == '0') ret.push_back(i);
				else if (a[i] == b[i] && a[i] == '1') hash_map[i] = 1;
			}
			else {
				if (a[i] == b[i] && a[i] == '1') ret.push_back(i);
				else if (a[i] == b[i] && a[i] == '0') hash_map[i] = 1;
			}
		}

		for (auto& x : ret) {
			if (hash_map.count(x + 1)) {
				cout << "YES" << "\n";
				return;
			}
		}
		cout << "NO" << "\n";
	}
	else {
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