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
		if (b == 1) {		//ע��ϸ�ڣ����b����1�Ļ���һ��Ҫ��һ�ε�
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
			if (ret > ans) {	//�Ƚ����޸ļ�b�����ж��ٸ�ֵ
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