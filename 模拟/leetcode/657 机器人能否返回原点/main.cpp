#include <iostream>
#include <string>
using namespace std;

bool judgeCircle(string moves) {
	int up = 0,left = 0;
	for (auto& s : moves) {
		if (s == 'U') ++up;
		else if (s == 'D') --up;
		else if (s == 'L') ++left;
		else --left;
	}
	return up == 0 && left == 0;
}

int main() {
	string moves = "LDRRLRUULR";
	cout << judgeCircle(moves) << endl;
	return 0;
}