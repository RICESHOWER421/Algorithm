#include <iostream>
#include <cmath>
using namespace std;

void Test() {
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	
	int ret = 0;
	if (a == 1) ++ret;
	if (b == 1) ++ret;
	if (c == 1) ++ret;
	
	if (ret == 3) cout << 3 << endl;
	else if (ret == 2) {
		if (a == b || b == c) {
			if (a == b) cout << 2 * c << endl;
			else cout << 2 * a << endl;
		}
		else cout << a + b + c << endl;
	}
	else if (ret == 1) {
		if (a == 1) cout << (b + 1) * c << endl;
		else if (b == 1) cout << max((a + 1) * c, (c + 1) * a) << endl;
		else cout << (b + 1) * a << endl;
	}
	else cout << a * b * c << endl;
}

int main() {
	Test();
	return 0;
}