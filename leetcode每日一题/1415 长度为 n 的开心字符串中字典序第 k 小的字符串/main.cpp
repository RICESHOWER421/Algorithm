#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        vector<char> s = { 'a', 'b', 'c' };
        int cur = 0;
        string path, ans;
        auto dfs = [&](auto&& dfs, int pos) {
            if (cur == k) return;
            if (pos == n) {
                ++cur;
                if (cur == k) ans = path;
                return;
            }

            for (int i = 0; i < 3; i++) {
                if (path.empty() || s[i] != path.back()) {
                    path += s[i];
                    dfs(dfs, pos + 1);
                    path.pop_back();
                }
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};

int main() {

	return 0;
}