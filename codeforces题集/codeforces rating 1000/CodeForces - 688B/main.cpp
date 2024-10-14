#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void Test() {
	string s;
	cin >> s;
	string ret = s;
	reverse(ret.begin(), ret.end());
	cout << s + ret << endl;
}

int main() {
	Test();
	return 0;
}