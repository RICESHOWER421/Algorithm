#include <bits/stdc++.h>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	map<int, int> hash_map;
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		hash_map[num]++;
	}

	for (int i = 1; i < 2048; i <<= 1) {
		hash_map[i << 1] += hash_map[i] / 2;
	}

	if (hash_map[2048]) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}
}
int main() {
	int n = 0;
	cin >> n;
	while (n--) {
		Test();
	}
	return 0;
}