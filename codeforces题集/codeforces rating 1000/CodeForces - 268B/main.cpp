#include <iostream>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	int left = 1, right = n - 1;
	int ans = 0;
	while (right) {
		ans += left * right;
		++left;
		--right;
	}
	cout << ans + n << endl;
}

int main() {
	Test();
	return 0;
}