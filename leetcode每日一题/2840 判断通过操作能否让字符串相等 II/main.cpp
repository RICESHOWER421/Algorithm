#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<int> c1(26), c2(26), c3(26), c4(26);
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                c1[s1[i] - 'a']++;
                c3[s2[i] - 'a']++;
            }
            else {
                c2[s1[i] - 'a']++;
                c4[s2[i] - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (c1[i] != c3[i] || c2[i] != c4[i]) return false;
        }
        return true;
    }

};
int main() {

	return 0;
}