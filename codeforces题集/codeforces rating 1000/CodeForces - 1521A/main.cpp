#include <iostream>
typedef long long ll;
using namespace std;

//���죬˵ʵ������������Ӵ����٣�����
void Test() {
	ll a = 0, b = 0;
	cin >> a >> b;
	if (b == 1) cout << "NO" << endl;	//���b��1�����������ܱ�1����
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