#include <iostream>
using namespace std;

void Test() {
	int a = 0, b = 0, n = 0, S = 0;
	cin >> a >> b >> n >> S;
	
	int num = S / n > a ? a : S / n;	//��Ҫ��ֵΪn��Ӳ�Ҹ���
	if (S - n * num <= b) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}