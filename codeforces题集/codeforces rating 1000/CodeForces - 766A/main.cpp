#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void Test() {
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 == s2) cout << -1 << endl;
	else cout << max(s1.size(), s2.size()) << endl;
}

int main() {
	Test();
	return 0;
}