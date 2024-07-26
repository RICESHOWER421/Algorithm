#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int longestSemiRepetitiveSubstring(string s) {
	int ans = 1, temp = 0;
	int left = 0, right = 1;
	while (right < s.size()) {
		if (temp == 2) {
			if (s[left] == s[left + 1]) --temp;
			++left;
			continue;
		}
		if (s[right] == s[right - 1]) ++temp;
		if (temp != 2) ans = max(ans, right - left + 1);
		++right;
	}
	return ans;
}

int main() {
	string s = "2233445566778899";
	cout << longestSemiRepetitiveSubstring(s) << endl;
	return 0;
}