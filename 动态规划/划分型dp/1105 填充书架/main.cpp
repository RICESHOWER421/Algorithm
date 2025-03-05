#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        //dp[i]表示前i本书所能达到的最小高度
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = 0x3f3f3f3f;
            int mx = 0, w = shelfWidth;
            for (int j = i; j > 0; j--) {
                w -= books[j - 1][0];
                if (w < 0) break;
                mx = max(mx, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + mx);
            }
        }
        return dp[n];
    }
};

int main() {

	return 0;
}