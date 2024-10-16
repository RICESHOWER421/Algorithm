#include <iostream>
using namespace std;
typedef long long ll;

void Test() {
	ll a = 0, b = 0, c = 0;
	cin >> a >> b >> c;

	int ans_1 = 0, ans_2 = 0;
	if (a >= c) ans_1 = -1;
	else ans_1 = 1;

	if (a * b <= c) ans_2 = -1;
	else ans_2 = b;
	cout << ans_1 << " " << ans_2 << endl;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}
