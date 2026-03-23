#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<int> heights(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]) heights[j]++;
                else heights[j] = 0;
            }
            vector<int> tmp = heights;
            sort(tmp.begin(), tmp.end());
            for (int i = 0; i < n; i++) {
                ans = max(ans, (n - i) * tmp[i]);
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}