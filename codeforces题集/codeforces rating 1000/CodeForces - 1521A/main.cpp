#include <iostream>
typedef long long ll;
using namespace std;

//构造，说实话这种类型题接触的少，难想
void Test() {
	ll a = 0, b = 0;
	cin >> a >> b;
	if (b == 1) cout << "NO" << endl;	//如果b是1，所有数都能被1整除
	else {
		cout << "YES" << endl;
		cout << a << " " << a * (b * b - 1) << " " << a * b * b << endl;
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