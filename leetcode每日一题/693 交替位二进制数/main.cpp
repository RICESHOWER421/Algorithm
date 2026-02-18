#include <iostream>
using namespace std;

bool hasAlternatingBits(int n) {
    int ret = n & 1;
    n >>= 1;
    while (n) {
        int temp = n & 1;
        if (temp == ret) return false;
        ret = n & 1;
        n >>= 1;
    }
    return true;
}

int main() {

	return 0;
}