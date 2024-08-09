#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
    int left = 0, right = 0;
    if (s.size() == 0 && t.size() == 0) return true;    //×¢ÒâÅÐ¶Ï¿Õ´®
    while (left < t.size()) {
        if (t[left] == s[right]) ++right;
        if (right == s.size()) return true;
        ++left;
    }
    return false;
}

int main() {

	return 0;
}