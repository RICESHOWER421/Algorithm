#include <iostream>
#include <cstdio>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;

	double ans = 0;
	for (int i = n; i >= 1; i--) {
		ans += 1.0 / i;
	}
	printf("%.12lf\n", ans);
}

int main() {
	Test();
	return 0;
}