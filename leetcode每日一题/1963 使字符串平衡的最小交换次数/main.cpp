#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        string ret;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ']') {
                if (ret.empty() || ret.back() != '[') {
                    ret += s[i];
                }
                else {
                    ret.pop_back();
                }
            }
            else {
                ret += s[i];
            }
        }

        int n = ret.size() / 2;
        return n / 2 + (n % 2 != 0);
    }
};

int main() {

    return 0;
}