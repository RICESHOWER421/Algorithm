#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 1e9 + 10, r = -1e9 - 10;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                l = min(l, matrix[i][j]);
                r = max(r, matrix[i][j]);
            }
        }

        while (l < r) {
            int mid = l + (r - l) / 2, cnt = 0;
            for (int i = 0; i < n; i++) {
                int left = 0, right = m - 1;
                while (left < right) {
                    int tmp = left + (right - left + 1) / 2;
                    if (matrix[i][tmp] <= mid) {
                        left = tmp;
                    }
                    else {
                        right = tmp - 1;
                    }
                }
                cnt += (left == 0 && matrix[i][left] > mid ? 0 : left + 1);
            }
            if (cnt >= k) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main() {
    vector<vector<int>> nums = { {1,5,9},{10,11,13},{12,13,15} };
    cout << Solution().kthSmallest(nums, 8) << "\n";
	return 0;
}