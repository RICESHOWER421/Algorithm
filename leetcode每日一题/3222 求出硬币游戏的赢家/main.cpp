#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    string losingPlayer(int x, int y) {
        return min(x, y / 4) % 2 == 0 ? "Bob" : "Alice";
    }
};

int main() {

	return 0;
}