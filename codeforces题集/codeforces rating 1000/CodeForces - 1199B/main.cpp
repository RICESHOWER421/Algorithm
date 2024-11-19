#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

void Test() {
	double H = 0, L = 0;
	cin >> H >> L;
	printf("%.13lf\n", (pow(L, 2) - pow(H, 2)) / (2 * H));
}
int main() {
	Test();
	return 0;
}