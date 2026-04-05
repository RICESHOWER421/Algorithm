#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool judgeCircle(string moves) {
		int up = 0, left = 0;
		for (auto& s : moves) {
			if (s == 'U') ++up;
			else if (s == 'D') --up;
			else if (s == 'L') ++left;
			else --left;
		}
		return up == 0 && left == 0;
	}
};

int main() {

	return 0;
}