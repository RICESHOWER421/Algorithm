#include <iostream>
using namespace std;

//��׼д����ѭ��
int addDigits(int num) {
	int sum = 0;
	if (!(num / 10)) return num;  //�Ը�λ����������
	while (num / 10) {
		int temp = num;
		sum = 0;
		while (temp) {
			sum += temp % 10;
			temp /= 10;
		}
		num = sum;
	}
	return sum;
}

//����д����ʱ�临�Ӷ�ΪO(1)
int addDigits(int num) {
	return (num - 1) % 9 + 1;
}

int main() {
	int num = 9;
	cout << addDigits(num) << endl;
	return 0;
}