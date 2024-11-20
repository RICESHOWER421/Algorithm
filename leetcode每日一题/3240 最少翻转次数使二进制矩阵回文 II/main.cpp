#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0, ret = 0;
        bool ok = false;
        for (int i = 0; i < m / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int ret0 = 0, ret1 = 0;
                if (grid[i][j]) ++ret1;
                else ++ret0;

                if (grid[i][n - j - 1]) ++ret1;
                else ++ret0;

                if (grid[m - i - 1][j]) ++ret1;
                else ++ret0;

                if (grid[m - i - 1][n - j - 1]) ++ret1;
                else ++ret0;

                if (ret1 && ret0) {
                    if (ret0 >= ret1) ans += ret1;
                    else ans += ret0;
                }
            }
        }

        if (m % 2) {
            for (int i = 0; i < n / 2; i++) {
                if (grid[m / 2][i] != grid[m / 2][n - i - 1]) {
                    ++ans;
                    ok = true;
                }
                else {
                    if (grid[m / 2][i]) ret += 2;
                }
            }
        }

        if (n % 2) {
            for (int i = 0; i < m / 2; i++) {
                if (grid[i][n / 2] != grid[m - i - 1][n / 2]) {
                    ++ans;
                    ok = true;
                }
                else {
                    if (grid[i][n / 2]) ret += 2;
                }
            }
        }

        if (m % 2 && n % 2) {
            if (grid[m / 2][n / 2]) ++ans;
        }
        return ans + (ret % 4 == 0 ? 0 : (ok ? 0 : 2));
    }
};

int main() {
    vector<vector<int>> grid = { {0,1,1,0,0,1,0,0,0,1,1,0,0,0},{1,0,1,0,0,1,1,1,1,0,0,1,1,0}};
    cout << Solution().minFlips(grid) << "\n";
	return 0;
}