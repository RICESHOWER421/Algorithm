#include <iostream>
#include <cmath>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	if (n % 2) cout << 0 << endl;
	else cout << (long long)pow(2, n / 2) << endl;
}

int main() {
	Test();
	return 0;
}