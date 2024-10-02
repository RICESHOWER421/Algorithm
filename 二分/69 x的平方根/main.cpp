#include <iostream>
using namespace std;
int mySqrt(int x) {
	if (x < 1) return 0;
	int left = 1, right = x;
	while (left < right) {
		int mid = left + (right - left + 1) / 2;
		if ((long long)mid * mid <= x) left = mid;
		else right = mid - 1;
	}
	return left;
}

int main() {
	cout << mySqrt(2147395599) << endl;
	return 0;
}