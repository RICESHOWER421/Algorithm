#include <iostream>
#include <string>
using namespace std;

int divisorSubstrings(int num, int k) {
	string s = to_string(num);
	int ret = 0;
	for (int i = 0; i <= s.size() - k; i++) {
		int ans = atoi(s.substr(i, k).c_str());
		if (ans != 0 && num % ans == 0) ++ret;
	}
	return ret;
}

int main() {
	int num = 430043, k = 2;
	cout << divisorSubstrings(num, k) << endl;
	return 0;
}