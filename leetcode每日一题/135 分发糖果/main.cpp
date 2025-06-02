#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = n;
        for (int i = 0; i < n; i++) {
            int begin = i > 0 && ratings[i - 1] < ratings[i] ? i - 1 : i;
            while (i + 1 < n && ratings[i] < ratings[i + 1]) ++i;
            int top = i;
            while (i + 1 < n && ratings[i] > ratings[i + 1]) ++i;
            int r1 = top - begin, r2 = i - top;
            ans += (r1 * (r1 - 1) + r2 * (r2 - 1)) / 2 + max(r1, r2);
        }
        return ans;
    }
};

int main() {
    vector<int> ratings = { 5,3,7,3 };
    cout << Solution().candy(ratings) << "\n";
	return 0;
}