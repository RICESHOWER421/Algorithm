#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

void Test() {
	ll a = 0, b = 0;
	cin >> a >> b;


	if (a < b) {
		cout << 1 << "\n";
	}
	else if (a == b) {
		cout << 2 << "\n";
	}
	else {
		ll ans = INT_MAX;
		bool ok = true;
		ll ret = 0;
		if (b == 1) {		//注意细节，如果b等于1的话是一定要动一次的
			b = 2;
			++ret;
		}

		while(ok){
			ll num = a;
			ll count = 0;
			while (num) {
				num /= b;
				++count;
			}

			ans = min(ans, ret + count);
			if (ret > ans) {	//先进行修改加b次数判断再改值
				ok = false;
			}
			++ret;
			++b;
		}
		cout << ans << "\n";
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