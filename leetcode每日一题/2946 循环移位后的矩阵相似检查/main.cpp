#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 && mat[i][(j + k) % n] != mat[i][j]) {
                    return false;
                }
                if (i % 2 == 0 && mat[i][(k % n <= j ? j - (k % n) : n - (k % n - j))] != mat[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {

	return 0;
}