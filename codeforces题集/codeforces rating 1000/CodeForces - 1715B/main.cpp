#include <iostream>
typedef long long ll;
using namespace std;

void Test() {
	ll n = 0, k = 0, b = 0, s = 0;
	cin >> n >> k >> b >> s;
	
	if (k * b > s) {
		cout << -1 << "\n";
	}
	else {
		ll ret = s - (k * b + k - 1);
		if ((n - 1) * (k - 1) >= ret) {
			if (ret <= 0) {
				cout << s << " ";
				for (int i = 0; i < n - 1; i++) {
					cout << 0 << " ";
				}
				cout << "\n";
			}
			else {
				cout << k * b + k - 1 << " ";
				for (int i = 0; i < n - 1; i++) {
					if (ret >= k - 1) {
						ret -= k - 1;
						cout << k - 1 << " ";
					}
					else if (ret > 0 && ret < k - 1) {
						cout << ret << " ";
						ret = 0;
					}
					else {
						cout << 0 << " ";
					}
				}
				cout << "\n";
			}
		}
		else {
			cout << -1 << "\n";
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