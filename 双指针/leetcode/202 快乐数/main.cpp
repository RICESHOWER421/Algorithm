#include <iostream>
#include <vector>
using namespace std;

int BitSum(int n) {
	int sum = 0;
	while (n) {
		int temp = n % 10;
		sum += temp * temp;
		n /= 10;
	}
	return sum;
}

bool isHappy(int n) {
	int slow = n, fast = BitSum(n);
	while (slow != fast) {
		slow = BitSum(slow);
		fast = BitSum(BitSum(fast));
	}
	
	return slow == 1;
}

int main() {
	cout << isHappy(2) << endl;
	return 0;
}