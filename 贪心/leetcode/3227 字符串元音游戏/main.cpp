#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        int ret = 0;
        for (auto& x : s) {
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') ++ret;
        }
        return ret;
    }
};

int main() {

	return 0;
}