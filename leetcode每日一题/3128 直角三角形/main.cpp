#include <iostream>
#include <vector>
using namespace std;
long long numberOfRightTriangles(vector<vector<int>>& grid) {
	long long ans = 0;
	vector<int> lines(grid.size());
	vector<int> rows(grid[0].size());
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j]) {
				++lines[i];
				++rows[j];
			}
		}
	}

	for (int i = grid.size() - 1; i >= 0; i--) {
		if (lines[i] <= 1) continue;
		for (int j = 0; j < grid[i].size(); j++) 
			if (grid[i][j] && rows[j]) ans += ((lines[i] - 1) * (rows[j] - 1));
	}
	return ans;
}

int main() {

	return;
}