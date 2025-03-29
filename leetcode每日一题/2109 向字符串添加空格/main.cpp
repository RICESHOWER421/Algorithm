#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int cur = 0;
        for (int i = 0; i < s.size(); i++) {
            if (cur < spaces.size() && i == spaces[cur]) {
                ++cur;
                ans += " ";
            }
            ans += s[i];
        }
        return ans;
    }
};

int main() {

	return 0;
}