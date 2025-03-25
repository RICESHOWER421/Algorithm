#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = i - 1, y = j - 1, c1 = 0, c2 = 0;
                vector<bool> hash_map(51);
                while (x >= 0 && y >= 0) {
                    c1 += (!hash_map[grid[x][y]]);
                    hash_map[grid[x--][y--]] = true;
                }

                for (int i = 0; i <= 50; i++) {
                    hash_map[i] = 0;
                }
                x = i + 1, y = j + 1;
                while (x < m && y < n) {
                    c2 += (!hash_map[grid[x][y]]);
                    hash_map[grid[x++][y++]] = true;
                }
                ans[i][j] = abs(c1 - c2);
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}