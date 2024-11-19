#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	string s;
	cin >> s;

	vector<int> ret1, ret2;
	for (int i = 0; i < n; i++){
		if (s[i] == '1') ret1.push_back(i);
		else ret2.push_back(i);
	}

	if (ret2.size() > 0 && ret2.size() < 3) {
		cout << "NO" << "\n";
	}
	else {
		cout << "YES" << "\n";
		vector<vector<char>> ans(n, vector<char>(n, '0'));
		for (int i = 0; i < n; i++) {
			ans[i][i] = 'X';
		}

		for (int i = 0; i < ret1.size(); i++) {
			for (int j = 0; j < n; j++) {
				if (ret1[i] != j) {
					ans[ret1[i]][j] = '=';
					ans[j][ret1[i]] = '=';
				}
			}
		}

		for (int i = 0; i < ret2.size(); i++) {
			if (i != ret2.size() - 1) {
				ans[ret2[i]][ret2[i + 1]] = '+';
				ans[ret2[i + 1]][ret2[i]] = '-';
			}
			else {
				ans[ret2[i]][ret2[0]] = '+';
				ans[ret2[0]][ret2[i]] = '-';
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (ans[i][j] == '0') cout << '=';
				else cout << ans[i][j];
			}
			cout << "\n";
		}
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