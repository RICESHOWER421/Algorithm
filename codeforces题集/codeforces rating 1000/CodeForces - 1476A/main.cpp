#include <iostream>
using namespace std;

//����Ҳwa���죬ԭ�����ϸ�ڸ�����û����ã�����д�Ļ���������
void Test() {
	int a = 0, b = 0;
	cin >> a >> b;
	if (b == 1) {
		cout << 1 << endl;
		return;
	}

	if (b < a) b = (a / b + (a % b != 0)) * b;
	cout << b / a + (b % a != 0) << endl;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}