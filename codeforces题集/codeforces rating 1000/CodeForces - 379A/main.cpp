#include <iostream>
using namespace std;

void Test() {
	int a = 0, b = 0;
	cin >> a >> b;
	
	int ans = 0;
	int c = 0; //c���Ѿ����������
	while (a) {
		ans += a;		//�����յ�ʱ��
		c += a;			//ת�����Ѿ����������
		a = c / b;		//���Ѿ����������ת�����µ�����
		c = c % b;		//���ܲ���ת�������������
	}
	cout << ans << endl;
}

int main() {
	Test();
	return 0;
}