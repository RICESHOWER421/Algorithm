#include <iostream>
typedef long long ll;
using namespace std;

void Test() {
	ll n = 0, x = 0, t = 0;
	cin >> n >> x >> t;

	if (x > t) {
		cout << 0 << "\n";
	}
	else {	
		if (t / x >= n) {	//间隔数大于总人数注意特判
			cout << (n - 1) * n / 2 << "\n";
		}
		else {
			cout << (n - (t / x)) * (t / x) + ((t / x - 1) * (t / x) / 2) << "\n";
		}
	}
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}