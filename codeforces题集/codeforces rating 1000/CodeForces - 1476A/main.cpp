#include <iostream>
using namespace std;

//这题也wa半天，原因就是细节根本就没处理好，构造写的还是生疏了
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