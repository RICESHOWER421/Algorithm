#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void Test() {
	string a, b;
	cin >> a >> b;

	int ans = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		for (int j = 0; j < (int)b.size(); j++) {
			int left = i, right = j;
			int ret = 0;
			while (left < a.size() && right < b.size() && a[left] == b[right]) {
				++ret;
				++left;
				++right;
			}
			ans = max(ans, ret);
		}
	}
	cout << a.size() - ans + b.size() - ans << "\n";
}
int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}