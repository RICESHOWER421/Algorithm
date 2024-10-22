#include <iostream>
#include <map>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;

	map<int, int> hash_map;
	bool ok = false;
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		if (!hash_map.count(num)) hash_map[num] = i;
		else {
			if (i - hash_map[num] != 1) {
				ok = true;
			}
		}
	}
	if (ok) cout << "YES" << "\n";
	else cout << "NO" << "\n";
}
int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}