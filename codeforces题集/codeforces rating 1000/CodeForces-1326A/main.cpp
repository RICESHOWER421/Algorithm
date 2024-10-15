#include <iostream>
using namespace std;

void Test() {
	int n = 0;
	cin >> n; 
	if (n == 1) cout << -1 << endl;
	else {
		string s;
		s += '2';
		for (int i = 0; i < n - 1; i++) s += '3';
		cout << s << endl;
	}
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}