#include <iostream>
#include <string>
using namespace std;

//a(sum(l)) + b
void Test() {
	int n = 0, a = 0, b = 0;
	cin >> n >> a >> b;
	string s;
	cin >> s;

	if (b >= 0) cout << n * a + n * b << endl;
	else {
		int ret_1 = 0, ret_2 = 0;
		bool ok = true;
		for (auto& x : s) {
			if (x == '0') {	//ok不能在这里做判断
				if (ok) {
					++ret_1;
					ok = false;
				}
			}
			else ok = true;
		}

		ok = true;
		for (auto& x : s) {
			if (x == '1') {	
				if (ok) {
					++ret_2;
					ok = false;
				}
			}
			else ok = true;
		}
		cout << n * a + (min(ret_1, ret_2) + 1)* b << endl;
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