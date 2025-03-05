#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) {
            return "";
        }

        bool ok = false;
        for (int i = 0; i < n / 2; i++) {
            if (palindrome[i] - 1 >= 'a') {
                palindrome[i] = 'a';
                ok = true;
                break;
            }
        }

        if (!ok) {
            palindrome.back()++;
        }
        return palindrome;
    }
};

int main() {

	return 0;
}