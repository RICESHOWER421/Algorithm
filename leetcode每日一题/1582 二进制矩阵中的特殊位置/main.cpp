#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), ans = 0;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) {
                    a[i]++;
                    b[j]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                for (int j = 0; j < m; j++) {
                    if (b[j] == 1 && mat[i][j]) ++ans;
                }
            }
        }
        return ans;
    }

};
int main() {

	return 0;
}