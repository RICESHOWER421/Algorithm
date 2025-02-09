#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	string s;
	cin >> s;

	if (n > 26) cout << -1 << "\n";
	else {
		int ans = 0;
		vector<int> hash_map(26);
		for (auto& x : s) {
			if (!hash_map[x - 'a']) hash_map[x - 'a'] = 1;
			else ++ans;
		}
		cout << ans << "\n";
	}
}
int main() {
	Test();
	return 0;
}