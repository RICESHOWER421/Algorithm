#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>> ret;
	sort(intervals.begin(), intervals.end());

	int left_num = intervals[0][0], right_num = intervals[0][1];
	for (int i = 1; i < intervals.size(); i++) {
		if (intervals[i][0] <= right_num) right_num = max(right_num, intervals[i][1]);
		else {
			ret.push_back({ left_num, right_num });
			left_num = intervals[i][0], right_num = intervals[i][1];
		}
	}
	ret.push_back({left_num, right_num});
	return ret;
}

int main() {
	vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} };
	vector<vector<int>> ret = merge(intervals);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i][0] << " " << ret[i][1] << endl;

	return 0;
}