#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0, l = points.size();
        for (int i = 1; i < l; i++) {
            int r1 = abs(points[i][0] - points[i - 1][0]), r2 = abs(points[i][1] - points[i - 1][1]);
            ans += min(r1, r2) + abs(r1 - r2);
        }
        return ans;
    }
};
int main() {

	return 0;
}