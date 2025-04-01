#include <bits/stdc++.h>
using namespace std;

//[[3, 2], [4, 3], [4, 4], [2, 5]]
//时间复杂度为O(N^2)，绝对会超时
//class Solution {
//public:
//    using ll = long long;
//    long long mostPoints(vector<vector<int>>& questions) {
//        int n = questions.size();
//        vector<ll> dp(n);  //dp[i]表示以i结尾所能得到的最高分数（答出第i题）
//        dp[0] = questions[0][0];
//        ll mx = dp[0];
//        for (int i = 1; i < n; i++) {
//            ll tmp = 0;
//            for (int j = 0; j < i; j++) {
//                if (j + questions[j][1] < i) {
//                    tmp = max(tmp, (ll)questions[j][0]);
//                }
//            }
//            dp[i] = (ll)questions[i][0] + tmp;
//            mx = max(mx, dp[i]);
//        }
//        return mx;
//    }
//};

class Solution {
public:
    using ll = long long;
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n + 1);   //dp[i]表示以i起始所能获得的最大分数
        for (int i = n - 1; i >= 0; i--) {
            int mx_pos = min(i + questions[i][1] + 1, n);
            dp[i] = max(dp[i + 1], dp[mx_pos] + questions[i][0]); //要么这个点不选，要么就选
        }
        return dp[0];
    }
};
int main() {
    vector<vector<int>> nums = { {3,2}, {4,3}, {4,4}, {2,5} };
    cout << Solution().mostPoints(nums) << "\n";
	return 0;
}