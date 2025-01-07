#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKeyChanges(string s) {
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            if (toupper(s[i]) != toupper(s[i - 1])) {
                ++ans;
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}
