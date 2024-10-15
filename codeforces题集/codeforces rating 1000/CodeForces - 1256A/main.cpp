#include <iostream>
using namespace std;

void Test() {
	int a = 0, b = 0, n = 0, S = 0;
	cin >> a >> b >> n >> S;
	
	int num = S / n > a ? a : S / n;	//需要价值为n的硬币个数
	if (S - n * num <= b) cout << "YES" << endl;
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