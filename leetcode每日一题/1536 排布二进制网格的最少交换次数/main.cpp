#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> cnts(n);
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = n - 1; j >= 0 && !grid[i][j]; j--) {
                ++cnt;
            }
            cnts[i] = cnt;
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (cnts[i] < n - i - 1) {
                bool ok = false;
                for (int j = i + 1; j < n; j++) {
                    if (cnts[j] >= n - i - 1) {
                        int cur = j;
                        while (cur > i) {
                            ++ans;
                            swap(cnts[cur], cnts[cur - 1]);
                            --cur;
                        }
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    return -1;
                }
            }
        }

        return ans;
    }
};

int main() {

	return 0;
}