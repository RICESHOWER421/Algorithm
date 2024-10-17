#include <iostream>
#include <string>
using namespace std;

void Test() {
	int a = 0, b = 0;
	cin >> a >> b;
	int ans = a + b;
	string s1 = to_string(a), s2 = to_string(b), s3 = to_string(ans);
	string ret_1, ret_2, ret_3;
	for (auto& x : s1) {
		if (x != '0') ret_1 += x;
	}

	for (auto& x : s2) {
		if (x != '0') ret_2 += x;
	}

	for (auto& x : s3) {
		if (x != '0') ret_3 += x;
	}

	if (atoi(ret_1.c_str()) + atoi(ret_2.c_str()) == atoi(ret_3.c_str())) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	Test();
	return 0;
}