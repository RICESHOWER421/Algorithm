#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	string ans;
	for (auto& x : s) {
		if (x >= 'A' && x <= 'Z') x += ' ';
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y') continue;
		ans += '.';
		ans += x;
	}
	cout << ans << endl;
	return 0;
}