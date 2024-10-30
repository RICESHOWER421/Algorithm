#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m));

        vector<int> rows(n), cols(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = min(rowSum[i] - rows[i] < 0 ? 0 : rowSum[i] - rows[i], colSum[j] - cols[j] < 0 ? 0 : colSum[j] - cols[j]);
                rows[i] += ans[i][j];
                cols[j] += ans[i][j];
            }
        }
        return ans;
    }
};

int main() {
    vector<int> rowSum = { 14,9 };
    vector<int> colSum = { 6,9,8 };
    vector<vector<int>> ans = Solution().restoreMatrix(rowSum, colSum);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

