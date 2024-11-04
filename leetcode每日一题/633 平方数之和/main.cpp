#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int ret = 1;
        if (c == 0) {
            return true;
        }
        while (c - pow(ret, 2) >= 0) {
            int num = c - pow(ret, 2);
            if ((int)sqrt(num) == sqrt(num)) {
                return true;
            }
            ++ret;
        }
        return false;
    }
};

int main() {

	return 0;
}