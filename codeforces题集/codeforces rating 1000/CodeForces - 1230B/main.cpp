#include <iostream>
using namespace std;

void Test() {
	int n = 0, k = 0;
	cin >> n >> k;
	string s;
	cin >> s;

	if (k == 0) cout << s << "\n";
	else if (s.size() == 1) cout << 0 << "\n";
	else {
		for (int i = 0; i < n && k; i++) {
			if (i == 0) {
				if (s[i] != '1') {
					--k;
					s[i] = '1';
				}
			}
			else {
				if (s[i] != '0') {
					--k;
					s[i] = '0';
				}
			}
		}
		cout << s << "\n";
	}
}
int main() {
	Test();
	return 0;
}
