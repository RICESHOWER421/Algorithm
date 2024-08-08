#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int balancedString(string s) {
	int a = 0, b = 0, c = 0, d = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'Q') ++a;
		if (s[i] == 'W') ++b;
		if (s[i] == 'E') ++c;
		if (s[i] == 'R') ++d;
	}
	
	a = a - (int)s.size() / 4 > 0 ? a - (int)s.size() / 4 : 0;
	b = b - (int)s.size() / 4 > 0 ? b - (int)s.size() / 4 : 0;
	c = c - (int)s.size() / 4 > 0 ? c - (int)s.size() / 4 : 0;
	d = d - (int)s.size() / 4 > 0 ? d - (int)s.size() / 4 : 0;
	if (a == 0 && b == 0 && c == 0 && d == 0) return 0;
	int ret_1 = 0, ret_2 = 0, ret_3 = 0, ret_4 = 0;
	int min_len = INT_MAX, left = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'Q') ++ret_1;
		if (s[i] == 'W') ++ret_2;
		if (s[i] == 'E') ++ret_3;
		if (s[i] == 'R') ++ret_4;
		if (ret_1 >= a && ret_2 >= b && ret_3 >= c && ret_4 >= d) {
			while (ret_1 >= a && ret_2 >= b && ret_3 >= c && ret_4 >= d) {
				min_len = min(min_len, i - left + 1);
				if (s[left] == 'Q' && a != 0) --ret_1;
				if (s[left] == 'W' && b != 0) --ret_2;
				if (s[left] == 'E' && c != 0) --ret_3;
				if (s[left] == 'R' && d != 0) --ret_4;
				++left;
			}
		}
	}
	return min_len;
}

int main() {
	string s = "QEWRQRWEQRWEQRRREQRWEQRWEQQRREWRQEWREQRWEEQRRRWEQRWEQREW";
	cout << balancedString(s) << endl;
	return 0;
}