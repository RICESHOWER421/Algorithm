#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ans;
    string path;

    void dfs(int pos, int end) {
        if (pos == end) {
            ans.push_back(path);
            return;
        }
        if (pos == 0) {
            for (int i = 0; i < 2; i++) {
                path += (i + '0');
                dfs(pos + 1, end);

                path.pop_back();
            }
        }
        else {
            if (path.back() == '1') {
                path += '0';
                dfs(pos + 1, end);

                path.pop_back();
            }
            path += '1';
            dfs(pos + 1, end);
            
            path.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        dfs(0, n);
        return ans;
    }
};

int main() {
    vector<string> ans = Solution().validStrings(1);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
	return 0;
}