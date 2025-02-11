#include <bits/stdc++.h>
using namespace std;

//abbaabbaabbaabba
void Test() {
	int n = 0;
	cin >> n;
	
	string tmp = "abba";
	int a = n / 4, b = n % 4;
	for (int i = 0; i < a; i++) {
		cout << tmp;
	}

	cout << tmp.substr(0, b) << "\n";
}
int main() {
	Test();
	return 0;
}