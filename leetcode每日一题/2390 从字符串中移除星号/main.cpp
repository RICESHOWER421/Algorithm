#include <iostream>
#include <string>
using namespace std;

string removeStars(string s) {
    string ret;
    for (auto& x : s) {
        if (x != '*') ret += x;
        else ret.pop_back();
    }
    return ret;
}

int main() {

	return 0;
}