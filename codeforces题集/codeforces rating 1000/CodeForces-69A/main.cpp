#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	string ret = "hello";
	int index = 0;
	bool ok = false;
	for (auto& x : s) {
		if (x == ret[index]) ++index;
		if (index == 5) {
			ok = true;
			break;
		}
	}

	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
