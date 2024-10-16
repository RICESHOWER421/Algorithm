#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	string s;
	cin >> s;

	vector<int> hash_map(26);
	string ret;

	for (auto& x : s) hash_map[x - 'a']++;
	for (int i = 0; i < 26; i++) {
		if (hash_map[i] % n == 0) {
			for (int j = 0; j < hash_map[i] / n; j++) {
				ret += (i + 'a');
			}
		}
		else {
			cout << -1 << endl;
			return;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ret;
	}
	cout << "\n";
}

int main() {
	Test(); 
	return 0;
}