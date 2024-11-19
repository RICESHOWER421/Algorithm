#include <iostream>
#include <string>
using namespace std;

void Test() {
	string a, b;
	cin >> a >> b;
	
	int ret = min(abs(a[0] - b[0]), abs(a[1] - b[1]));
	int count = max(abs(a[0] - b[0]), abs(a[1] - b[1]));
	cout << count << "\n";

	if (a[0] < b[0]) {
		if (a[1] < b[1]) {	
			for (int i = 0; i < ret; i++) {
				cout << "RU" << "\n";
			}

			for (int i = 0; i < count - ret; i++) {
				if (ret == abs(a[0] - b[0])) cout << "U" << "\n";
				else cout << "R" << "\n";
			}
		}
		else {
			for (int i = 0; i < ret; i++) {
				cout << "RD" << "\n";
			}

			for (int i = 0; i < count - ret; i++) {
				if (ret == abs(a[0] - b[0])) cout << "D" << "\n";
				else cout << "R" << "\n";
			}
		}
	}
	else {
		if (a[1] < b[1]) {
			for (int i = 0; i < ret; i++) {
				cout << "LU" << "\n";
			}

			for (int i = 0; i < count - ret; i++) {
				if (ret == abs(a[0] - b[0])) cout << "U" << "\n";
				else cout << "L" << "\n";
			}
		}
		else {
			for (int i = 0; i < ret; i++) {
				cout << "LD" << "\n";
			}

			for (int i = 0; i < count - ret; i++) {
				if (ret == abs(a[0] - b[0])) cout << "D" << "\n";
				else cout << "L" << "\n";
			}
		}
	}
}

int main() {
	Test();
	return 0;
}