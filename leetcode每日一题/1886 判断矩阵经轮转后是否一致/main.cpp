#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m = mat.size(), n = target.size(), x = 0, y = 0;
        bool ok = true;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (target[i][j] != mat[x][y]) {
                    ok = false;
                    break;
                }
                ++y;
            }
            if (!ok) break;
            ++x;
            y = 0;
        }

        if (ok) return true;
        ok = true;
        x = 0, y = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (target[j][i] != mat[x][y]) {
                    ok = false;
                    break;
                }
                ++y;
            }
            if (!ok) break;
            ++x;
            y = 0;
        }

        if (ok) return true;
        ok = true;
        x = 0, y = 0;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (target[i][j] != mat[x][y]) {
                    ok = false;
                    break;
                }
                ++y;
            }
            if (!ok) break;
            ++x;
            y = 0;
        }
        if (ok) return true;
        ok = true;
        x = 0, y = 0;;

        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (target[j][i] != mat[x][y]) {
                    ok = false;
                    break;
                }
                if (!ok) break;
                ++y;
            }
            ++x;
            y = 0;
        }
        if (ok) return true;
        return false;
    }
};

int main() {

	return 0;
}