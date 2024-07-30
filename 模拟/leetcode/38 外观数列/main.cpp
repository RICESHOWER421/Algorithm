#include <iostream>
#include <string>
using namespace std;
string countAndSay(int n) {
	string origin_str = "1";
	string return_str;
	if (n == 1) return origin_str;
	int num = n - 1;
	while (num--) {
		return_str = "";
		int count = 0, kinds = -1;
		for (int i = 0; i < origin_str.size(); i++) {
			if (kinds != origin_str[i] - '0') {
				if (kinds != -1) {
					return_str += count + '0';
					return_str += kinds + '0';
				}
				kinds = origin_str[i] - '0';
				count = 0;
			}
			++count;
		}
		if (count != 0 && kinds != -1) {
			return_str.push_back(count + '0');
			return_str.push_back(kinds + '0');
		}
		origin_str = return_str;
	}
	return return_str;
}

int main() {
	cout << countAndSay(30) << endl;
	return 0;
}