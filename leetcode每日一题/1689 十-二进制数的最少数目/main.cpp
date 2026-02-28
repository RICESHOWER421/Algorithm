#include <iostream>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int ret = 0;
        for (auto& x : n) {
            if (x - '0' > ret) ret = x - '0';
        }
        return ret;
    }
};

int main() {

	return 0;
}