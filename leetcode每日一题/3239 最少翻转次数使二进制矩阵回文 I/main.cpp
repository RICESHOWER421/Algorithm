#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int a = 0, b = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n / 2; j++) {
                a += grid[i][j] != grid[i][n - j - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m / 2; j++) {
                b += grid[j][i] != grid[m - j - 1][i];
            }
        }
        return min(a, b);
    }
};

int main() {
    vector<vector<int>> grid = { {0,1},{0,1},{0,0} };
    cout << Solution().minFlips(grid) << "\n";
	return 0;
}