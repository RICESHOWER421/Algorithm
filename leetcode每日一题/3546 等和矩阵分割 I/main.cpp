#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        ll sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
        }

        ll tmp = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp += grid[i][j];
            }
            if (sum - tmp == tmp) return true;
        }

        tmp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp += grid[j][i];
            }
            if (sum - tmp == tmp) return true;
        }
        return false;
    }
};

int main() {

	return 0;
}