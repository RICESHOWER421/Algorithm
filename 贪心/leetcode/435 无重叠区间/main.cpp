#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end());
	
	int right = intervals[0][1];
	int ret = 0;
	for (int i = 1; i < intervals.size(); i++) {
		if (intervals[i][0] < right) right = min(right, intervals[i][1]);
		else {
			++ret;
			right = intervals[i][1];
		}
	}
	return intervals.size() - (ret + 1);
}

int main() {
	vector<vector<int>> intervals = { {1,2},{2,3},{3,4},{1,3} };
	cout << eraseOverlapIntervals(intervals) << endl;
 	return 0;
}