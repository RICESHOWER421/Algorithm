#include <iostream>
using namespace std;

void Test() {
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;

	int num = n / k;	//ÿ����ҵ�����
	if (num >= m) cout << m << endl;
	else cout << num - ((m - num) / (k - 1) + ((m - num) % (k - 1) != 0)) << endl;	//�Թ�ʽ������һ��Ҫ��ע��
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}