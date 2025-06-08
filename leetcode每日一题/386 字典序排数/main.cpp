#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        string path;
        auto dfs = [&](auto&& dfs)->void {
            if (atoi(path.c_str()) <= n) ans.push_back(atoi(path.c_str()));

            for (int i = 0; i <= 9; i++) {
                path += (i + '0');
                if (atoi(path.c_str()) > n) {
                    path.pop_back();
                    return;
                }
                dfs(dfs);
                path.pop_back();
            }
        };
        for (int i = 1; i <= 9; i++) {
            path += (i + '0');
            dfs(dfs);
            path.pop_back();
        }
        return ans;
    }
};

int main() {
    vector<int> ans = Solution().lexicalOrder(13);
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}