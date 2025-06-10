#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        vector<int> cnts(26);
        for (auto& x : s) {
            cnts[x - 'a']++;
        }

        int mx = 0, mn = 101;
        for (int i = 0; i < 26; i++) {
            if (cnts[i]) {
                if (cnts[i] % 2) mx = max(mx, cnts[i]);
                else mn = min(mn, cnts[i]);
            }
        }
        return mx - mn;
    }
};

int main() {

	return 0;
}