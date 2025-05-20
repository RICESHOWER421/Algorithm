#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        int l = 0, r = m + 1;

        auto check = [&](int mid) -> bool {
            vector<int> dp(n), tmp = nums;
            for (int i = 0; i < mid; i++) {
                dp[queries[i][0]] += queries[i][2];
                if (queries[i][1] + 1 < n) dp[queries[i][1] + 1] -= queries[i][2];
            }
            for (int i = 1; i < n; i++) {
                dp[i] += dp[i - 1];
            }
            for (int i = 0; i < n; i++) {
                tmp[i] -= dp[i];
            }

            // cout << mid << "\n";
            // for(int i = 0; i < n; i++){
            //     cout << tmp[i] << " ";
            // }
            // cout << "\n";
            for (int i = 0; i < n; i++) {
                if (tmp[i] > 0) return false;
            }
            return true;
        };

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l == m + 1 ? -1 : l;
    }
};

int main() {
	
	return 0;
}