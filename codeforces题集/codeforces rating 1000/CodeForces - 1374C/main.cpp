#include <iostream>
#include <string>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	string s;
	cin >> s;
	
	string st;
	for (auto& x : s) {
		if (x == '(') st += x;
		else {
			if (!st.empty()) st.pop_back();
		}
	}
	cout << (int)st.size() << endl;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}