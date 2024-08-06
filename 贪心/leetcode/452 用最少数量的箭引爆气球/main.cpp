#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//[1,2][1,3][1,4][2,3][2,4][2,5][3,9]
int findMinArrowShots(vector<vector<int>>& points) {
	sort(points.begin(), points.end());
	int left = points[0][0], right = points[0][1];
	int ret = 0;
	for (int i = 1; i < points.size(); i++) {
		if (points[i][0] <= right) {
			left = max(left, points[i][0]);
			right = min(right, points[i][1]);
		}
		else {
			++ret;
			left = points[i][0];
			right = points[i][1];
		}
	}
	return ret + 1;
}

int main() {
	vector<vector<int>> points = { {1,2},{2,3},{3,4},{4,5} };
	cout << findMinArrowShots(points) << endl;
	return 0;
}