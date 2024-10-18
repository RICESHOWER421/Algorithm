#include <iostream>
using namespace std;

//(n - 2) * 180 = ans / ((ans / 180) + 2) = a
void Test() {
	int a = 0;
	cin >> a;
	if ((360 * a / (180 - a)) % 180 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}