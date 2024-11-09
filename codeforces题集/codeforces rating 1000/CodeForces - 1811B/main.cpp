#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

void Test() {
	ll n = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	cin >> n >> x1 >> y1 >> x2 >> y2;

	ll pos1 = n + 1 - min(x1, y1) >= max(x1, y1) ? min(x1, y1) : n + 1 - max(x1, y1);
	ll pos2 = n + 1 - min(x2, y2) >= max(x2, y2) ? min(x2, y2) : n + 1 - max(x2, y2);
	cout << abs(pos1 - pos2) << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}