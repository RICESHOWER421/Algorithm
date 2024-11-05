#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        string temp = s;
        reverse(temp.begin(), temp.end());
        return s == temp ? 1 : 2;
    }
};

int main() {

	return 0;
}