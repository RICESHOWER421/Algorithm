#include <iostream>
#include <string>
using namespace std;

string getSmallestString(string s, int k) {
	int ret = 0;
	for (int i = 0; i < s.size(); i++) {
		int ans = s[i] - 'a' + 1;
		if (s[i] == 'a') continue;
		else if (ans > 14 && ret + (27 - ans) <= k) {
			ret += (27 - ans);
			s[i] = 'a';
		}
		else if (ans <= 14 && ret + (ans - 1) <= k) {
			ret += (ans - 1);
			s[i] = 'a';
		}
		else {
			s[i] -= (k - ret);
			break;
		}
	}
	return s;
}
int main() {
	string s = "xaxcd";
	int k = 4;
	cout << getSmallestString(s, k) << endl;
	return 0;
}