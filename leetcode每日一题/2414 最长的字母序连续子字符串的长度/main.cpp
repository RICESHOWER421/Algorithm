#include <iostream>
#include <string>
using namespace std;

int longestContinuousSubstring(string s) {
    int ans = 0;
    int left = 0, right = 0;
    while (right < (int)s.size()) {
        if (left == right || (right > 0 && s[right] == s[right - 1] + 1)) {
            ans = max(ans, right - left + 1);
            ++right;
        }
        else left = right;
    }
    return ans;
}

int main() {

	return 0;
}