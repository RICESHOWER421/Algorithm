#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Test() {
	string s;
	cin >> s;
	int n = 0;
	cin >> n;

	int sum = 0;
	vector<int> hash_map(26);
	for (auto& x : s) {
		sum += (x - 'a' + 1);
		hash_map[x - 'a']++;
	}

	if (sum <= n) cout << s << "\n";
	else {
		vector<int> count(26);
		int ret = sum - n;
		for (int i = 25; i >= 0; i--) {
			if (ret >= hash_map[i] * (i + 1)) {
				ret -= hash_map[i] * (i + 1);
				count[i] = hash_map[i];
			}
			else {
				count[i] = ret / (i + 1) + (ret % (i + 1) != 0);
				break;
			}
		}

		for (int i = 0; i < (int)s.size(); i++) {
			if (count[s[i] - 'a']) --count[s[i] - 'a'];
			else cout << s[i];
		}
		cout << "\n";
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