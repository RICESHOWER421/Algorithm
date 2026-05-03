#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s == goal) return true;
        int n = s.size();
        string tmp;
        for (int i = 0; i < n; i++) {
            tmp += s[i];
            if (s.substr(i + 1) + tmp == goal) return true;
        }
        return false;
    }
};

int main() {

	return 0;
}