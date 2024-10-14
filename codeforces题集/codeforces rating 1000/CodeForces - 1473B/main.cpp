#include <iostream>
#include <string>
using namespace std;

int gcd(int x, int y) {
	while (x % y) {
		int temp = x % y;
		x = y;
		y = temp;
	}
	return y;
}

int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

void Test() {
	string s1, s2;
	cin >> s1 >> s2;
	int num = lcm((int)s1.size(), (int)s2.size());
	
	string ret_1, ret_2;
	for (int i = 0; i < num / (int)s1.size(); i++) ret_1 += s1;
	for (int i = 0; i < num / (int)s2.size(); i++) ret_2 += s2;
	if (ret_1 == ret_2) cout << ret_1 << endl;
	else cout << -1 << endl;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}