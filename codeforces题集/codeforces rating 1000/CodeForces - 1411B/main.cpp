#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

void Test() {
	ll n = 0;
	cin >> n;
	
	ll tmp = n;
	while (tmp) {
		if (tmp % 10) {
			if (n % (tmp % 10)) {
				++n;
				tmp = n;
			}
			else tmp /= 10;
		}
		else tmp /= 10;
	}
	cout << n << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}