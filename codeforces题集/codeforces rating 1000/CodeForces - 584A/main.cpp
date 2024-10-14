#include <iostream>
using namespace std;

void Test() {
	int n = 0, t = 0;
	cin >> n >> t;
	if (n == 1 && t == 10) cout << -1 << endl;
	else {
		string s;
		if (t >= 2 && t <= 9) {
			for (int i = 0; i < n; i++) s += (t + '0');
		}
		else {
			for (int i = 0; i < n - 2; i++) {
				s += '1';
			}
			s += '1';
			s += '0';
		}
		cout << s << endl;
	}
}
int main() {
	Test();
	return 0;
}