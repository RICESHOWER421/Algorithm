#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<vector<int>> rets(26);
        vector<bool> vis(n);
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') rets[s[i] - 'a'].push_back(i);
            else {
                for (int i = 0; i < 26; i++) {
                    if (!rets[i].empty()) {
                        vis[rets[i].back()] = true;
                        rets[i].pop_back();
                        break;
                    }
                }
            }
        }

        string ans;
        for (int i = 0; i < n; i++) {
            if (s[i] != '*' && !vis[i]) ans += s[i];
        }
        return ans;
    }
};

int main() {

	return 0;
}