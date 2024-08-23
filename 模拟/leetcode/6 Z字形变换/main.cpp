#include <string>
#include <iostream>
using namespace std;

string convert(string s, int numRows) {
	string return_str;
	if (numRows == 1) return s;
	int d = (numRows - 1) * 2;
	for (int i = 0; i < numRows; i++) {
		int index = i;
		while (index < s.size()) {
			return_str += s[index];
			if (index + d - 2 * i < s.size() && i != 0 && i != numRows - 1) return_str += s[index + d - 2 * i];
			index += d;
		}
	}
	return return_str;
}

int main() {
	string s = "ABC";
	cout << convert(s, 2) << endl;
	return 0;
}