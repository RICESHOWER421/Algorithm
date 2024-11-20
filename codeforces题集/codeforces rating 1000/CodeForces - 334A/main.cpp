#include <iostream>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	int left = 1, right = n * n;
	int count = n / 2, ret = 0;
	while (left < right) {
		if (ret < count) {
			cout << left << " " << right << " ";
			++left;
			--right;
			++ret;
			if (ret == count) {
				ret = 0;
				cout << "\n";
			}
		}
	}
}

int main() {
	Test();
	return 0;
}