#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int cur = k - 1;
        for (int i = x; i <= x + k / 2 - 1; i++) {
            for (int j = y; j <= y + k - 1; j++) {
                swap(grid[i][j], grid[i + cur][j]);
            }
            cur -= 2;
        }
        return grid;
    }
};


int main() {

	return 0;
}