#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
	sort(points.begin(), points.end(), [](const vector<int>& s1, const vector<int>& s2) {
		return s1[0] > s2[0];
	});

	int ret = 0;
	int left = 0, right = 1;
	while (right < points.size()) {
		if (points[left][0] - points[right][0] > w) {
			++ret;
			left = right;
		}
		else ++right;
	}
	return ret + 1;
}

int main() {
	vector<vector<int>> points = { {0,0} ,{1,1},{2,2},{3,3},{4,4},{5,5},{6,6} };
	int w = 2;
	cout << minRectanglesToCoverPoints(points, w) << endl;
	return 0;
}