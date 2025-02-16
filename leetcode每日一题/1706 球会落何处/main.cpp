#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;

    int check(int x, int y, bool& ok) {
        if (x == n - 1) {
            if (ok) {
                return y + 1;
            }
            else {
                return y - 1;
            }
        }
        else {
            return -1;
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<int> ans(m);

        for (int i = 0; i < m; i++) {
            int x = 0, y = i;
            bool ok = true; //真表示可以往右下角走，假表示可以往左下角走
            if (y + 1 < m && grid[x][y + 1] == 1 && grid[x][y] == 1) {
                ok = true;
            }
            else if (y - 1 >= 0 && grid[x][y - 1] == -1 && grid[x][y] == -1) {
                ok = false;
            }
            else {
                ans[i] = -1;
                continue;
            }

            while (true) {
                if (ok) {
                    if (y + 2 < m && x + 1 < n && grid[x + 1][y + 2] == 1 && grid[x + 1][y + 1] == 1) {
                        ++x;
                        ++y;
                    }
                    else if (x + 1 < n && y + 1 < m && grid[x + 1][y + 1] == -1 && grid[x + 1][y] == -1) {
                        ++x;
                        ++y;
                        ok = false;
                    }
                    else{
                        ans[i] = check(x, y, ok);
                        break;
                    }
                }
                else {
                    if (x + 1 < n && y - 2 >= 0 && grid[x + 1][y - 2] == -1 && grid[x + 1][y - 1] == -1) {
                        ++x;
                        --y;
                    }
                    else if (x + 1 < n && y - 1 >= 0 && grid[x + 1][y - 1] == 1 && grid[x + 1][y] == 1) {
                        ++x;
                        --y;
                        ok = true;
                    }
                    else {
                        ans[i] = check(x, y, ok);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> grid = { {1,1,1,1,1,1},
                                {-1,-1,-1,-1,-1,-1},
                                {1,1,1,1,1,1},
                                {-1,-1,-1,-1,-1,-1} };

    vector<int> ans = Solution().findBall(grid);
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << "\n";
	return 0;
}