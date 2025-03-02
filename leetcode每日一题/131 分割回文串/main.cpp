#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;

        auto dfs = [&](auto&& dfs, int pos) -> void { 
            if (pos == s.size()) {
                ans.push_back(path);
                return;
            }

            int cur = 0;
            string ret;
            for (int i = pos; i < s.size(); i++) {
                ret += s[i];
                ++cur;
                string tmp = ret;
                reverse(tmp.begin(), tmp.end());
                if (tmp == ret) {
                    path.push_back(ret);
                    dfs(dfs, pos + cur);
                    path.pop_back();
                }
            }
        };

        dfs(dfs, 0);
        return ans;
    }
};

int main() {
    vector<vector<string>> ans = Solution().partition("aabaa");
    for (auto& x : ans) {
        for (auto& y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
	return 0;
}