#include <iostream>
#include <vector>
using namespace std;

bool satisfiesConditions(vector<vector<int>>& grid) {
    for (int i = 0; i < grid[0].size(); i++) {
        if (i > 0) {
            if (grid[0][i] == grid[0][i - 1]) return false;
        }
        int num = grid[0][i];
        for (int j = 1; j < grid.size(); j++) {
            if (grid[j][i] != num) return false;
        } 
    }
    return true;
}

int main() {
    vector<vector<int>> grid = { {1,1,1},{2,2,2} };
    cout << satisfiesConditions(grid) << endl;
	return 0;
}