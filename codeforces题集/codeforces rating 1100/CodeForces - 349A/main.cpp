#include <iostream>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;

	int ret_1 = 0, ret_2 = 0;
	while (n--) {
		int num = 0;
		cin >> num;
		if (num == 25) ++ret_1;
		else if (num == 50) {
			++ret_2;
			if (ret_1) --ret_1;
			else {
				cout << "NO" << "\n";
				return;
			}
		}
		else {
			if (ret_2 && ret_1) {
				--ret_1;
				--ret_2;
			}
			else if (ret_1 >= 3) {
				ret_1 -= 3;
			}
			else {
				cout << "NO" << "\n";
				return;
			}
		}
	}
	cout << "YES" << "\n";
}
int main() {
	Test();
	return 0;
}