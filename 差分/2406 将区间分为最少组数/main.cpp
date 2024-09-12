#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minGroups(vector<vector<int>>& intervals) {
    int num = 0;
    for (int i = 0; i < intervals.size(); i++) {
        num = max({ num, intervals[i][0], intervals[i][1] });
    }
    vector<int> diff(num);

    int max_num = -1;
    for (int i = 0; i < intervals.size(); i++) {
        int left = intervals[i][0] - 1, right = intervals[i][1] - 1;
        diff[left] += 1;
        if (right + 1 < num) {
            diff[right + 1] -= 1;
        }
    }

    for (int i = 1; i < num; i++) {
        diff[i] += diff[i - 1];
    }

    for (int i = 0; i < num; i++) {
        max_num = max(max_num, diff[i]);
    }
    return max_num;
}

int main() {

	return 0;
}