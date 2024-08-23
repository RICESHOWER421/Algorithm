#include <iostream>
using namespace std;

//标准写法，循环
int addDigits(int num) {
	int sum = 0;
	if (!(num / 10)) return num;  //对个位数进行特判
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

//特殊写法，时间复杂度为O(1)
int addDigits(int num) {
	return (num - 1) % 9 + 1;
}

int main() {
	int num = 9;
	cout << addDigits(num) << endl;
	return 0;
}