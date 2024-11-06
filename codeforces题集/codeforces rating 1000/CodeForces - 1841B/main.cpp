#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	
	bool ok = true;
	int begin = -1, mx = -1;
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		if (i == 0) begin = num;
		if (num >= mx) {
			if (ok) {
				cout << "1";
				mx = num;
			}
			else {
				if (num <= begin) {
					cout << "1";
					mx = num;
				}
				else {
					cout << "0";
				}
			}
		}
		else {
			if (num <= begin && ok) {
				cout << "1";
				ok = false;
				mx = num;
			}
			else {
				cout << "0";
			}
		}
	}
	cout << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}