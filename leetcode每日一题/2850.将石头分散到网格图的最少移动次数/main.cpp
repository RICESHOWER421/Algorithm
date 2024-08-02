#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

int minimumMoves(vector<vector<int>>& grid) {
    vector<pair<int, int>> zero;
    vector<pair<int, int>> nums;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] > 1) {
                for (int k = 2; k <= grid[i][j]; ++k) {
                    nums.emplace_back(i, j);
                }
            }
            else if (grid[i][j] == 0) {
                zero.emplace_back(i, j);
            }
        }
    }

    int ret = INT_MAX;
    do {
        int steps = 0;
        for (int i = 0; i < nums.size(); ++i) {
            steps += abs(nums[i].first - zero[i].first) + abs(nums[i].second - zero[i].second);
        }
        ret = min(ret, steps);
    } while (next_permutation(nums.begin(), nums.end()));
    return ret;
}

int main() {
	vector<vector<int>> grid = { {1,2,2}, {1,1,0}, {0,1,1}};
	cout << minimumMoves(grid) << endl;
	return 0;
}