#include <iostream>
using namespace std;

bool checkRecord(string s) {
	int count_A = 0, count_L = 0;
	for (auto c : s) {
		if (c == 'L') ++count_L;
		else {
			if (c == 'A') ++count_A;
			count_L = 0;
		}
		if (count_A >= 2 || count_L >= 3) return false;
	}
	return true;
}
int main() {

	return 0;
}