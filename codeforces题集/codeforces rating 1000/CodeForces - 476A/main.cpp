#include <iostream>
using namespace std;

void Test() {
	int n = 0, k = 0;
	cin >> n >> k;

	int step = n;
	int ans = -1;
	while (n >= 0) {
		if (step % k == 0) ans = step;
		step--;
		n -= 2;
	}
	cout << ans << endl;
}

int main() {
	Test();
	return 0;
}