#include <iostream>
#include <string>
using namespace std;

//1 1 1 0
//0 0 0 0
//1 0 1 1
//0 1 1 1
//如果1要变成0，就需要跟不需要改变的数字1进行匹配
//如果0要变成1，就需要跟不需要改变的数字1进行匹配
//001
//110
class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        bool ok1 = false, ok2 = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1' && target[i] == '1') return true;
            if (s[i] == '0' && target[i] == '1') ok1 = true;
            if (s[i] == '1') ok2 = true;
            if (ok1 && ok2) return true;
        }
        return false;
    }
};

int main() {

	return 0;
}