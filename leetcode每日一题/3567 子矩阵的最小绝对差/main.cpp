#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));
        int x = 0, y = 0;
        for (int i = 0; i < n - k + 1; i++) {
            for (int j = 0; j < m - k + 1; j++) {
                set<int> s;
                for (int l = i; l < i + k; l++) {
                    for (int m = j; m < j + k; m++) {
                        s.insert(grid[l][m]);
                    }
                }

                if (s.size() == 1) {
                    ans[x][y] = 0;
                }
                else {
                    int tmp = -1e5 + 10, mn = 0x3f3f3f3f;
                    for (auto& x : s) {
                        if (tmp == -1e5 + 10) {
                            tmp = x;
                        }
                        else {
                            mn = min(mn, abs(x - tmp));
                            tmp = x;
                        }
                    }
                    ans[x][y] = mn;
                }
                ++y;
                if (y == ans[0].size()) {
                    ++x;
                    y = 0;
                }
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}