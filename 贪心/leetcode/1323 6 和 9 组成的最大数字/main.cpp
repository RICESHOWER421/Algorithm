#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maximum69Number(int num) {
        string ret = to_string(num);
        for (int i = 0; i < ret.size(); i++) {
            if (ret[i] == '6') {
                ret[i] = '9';
                break;
            }
        }
        return atoi(ret.c_str());
    }
};

int main() {

	return 0;
}