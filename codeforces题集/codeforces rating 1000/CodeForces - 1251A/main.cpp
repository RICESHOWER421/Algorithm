#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void Test() {
	string s;
	cin >> s;

	vector<int> hash_map(26, 3);
	int cur = 0;
	while (cur < s.size()) {
		if (cur + 1 < s.size() && s[cur] == s[cur + 1]) {
			hash_map[s[cur] - 'a'] = min(2, hash_map[s[cur] - 'a']);
			cur += 2;
		}
		else {
			hash_map[s[cur] - 'a'] = 1;
			++cur;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (hash_map[i] == 1) {
			cout << (char)(i + 'a');
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