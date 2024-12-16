#include <iostream>
#include <vector>
using namespace std;

//¼ÇÒä»¯ËÑË÷
class Solution {
public:
    vector<pair<int, int>> dist = { {-2,-1},{-1,-2},{-2,1},{-1,2},{1,2},{2,1},{1,-2},{2,-1} };
    double dfs(int n, int k, int x, int y, vector<vector<vector<double>>>& vis) {
        if ((x < 0 || x >= n) || (y < 0 || y >= n)) {
            return 0;
        }

        if (k == 0) {
            return 1;
        }

        double tmp = vis[k][x][y];
        if (tmp) {
            return tmp;
        }

        double ans = 0;
        for (auto& pos : dist) {
            ans += dfs(n, k - 1, x + pos.first, y + pos.second, vis);
        }

        ans /= 8;
        vis[k][x][y] = ans;
        return ans;
    }


    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> vis(k + 1, vector<vector<double>>(n, vector<double>(n)));
        return dfs(n, k, row, column, vis);
    }
};
int main() {

	return 0;
}