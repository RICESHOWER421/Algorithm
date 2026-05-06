#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (boxGrid[i][j] == '#') ++cnt;
                else if (boxGrid[i][j] == '*') {
                    ans[j][m - i - 1] = '*';
                    int pos = j - 1;
                    while (pos >= 0 && cnt) {
                        ans[pos][m - 1 - i] = '#';
                        --pos;
                        --cnt;
                    }
                }
            }
            //最后底部如果没有障碍物，那么需要特殊处理
            if (boxGrid[i][n - 1] != '*') {
                int pos = n - 1;
                while (pos >= 0 && cnt) {
                    ans[pos][m - 1 - i] = '#';
                    --pos;
                    --cnt;
                }
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}