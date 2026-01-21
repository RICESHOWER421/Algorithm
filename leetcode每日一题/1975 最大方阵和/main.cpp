#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        int ret = 0, mn = INT_MAX;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < 0) ++ret;
                ans += abs(matrix[i][j]);
                mn = min(abs(matrix[i][j]), mn);
            }
        }
        return ret % 2 == 0 ? ans : ans - 2 * mn;
    }
};

int main() {

	return 0;
}