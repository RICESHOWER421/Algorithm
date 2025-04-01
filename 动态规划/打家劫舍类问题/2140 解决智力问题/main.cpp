#include <bits/stdc++.h>
using namespace std;

//[[3, 2], [4, 3], [4, 4], [2, 5]]
//ʱ�临�Ӷ�ΪO(N^2)�����Իᳬʱ
//class Solution {
//public:
//    using ll = long long;
//    long long mostPoints(vector<vector<int>>& questions) {
//        int n = questions.size();
//        vector<ll> dp(n);  //dp[i]��ʾ��i��β���ܵõ�����߷����������i�⣩
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
        vector<ll> dp(n + 1);   //dp[i]��ʾ��i��ʼ���ܻ�õ�������
        for (int i = n - 1; i >= 0; i--) {
            int mx_pos = min(i + questions[i][1] + 1, n);
            dp[i] = max(dp[i + 1], dp[mx_pos] + questions[i][0]); //Ҫô����㲻ѡ��Ҫô��ѡ
        }
        return dp[0];
    }
};
int main() {
    vector<vector<int>> nums = { {3,2}, {4,3}, {4,4}, {2,5} };
    cout << Solution().mostPoints(nums) << "\n";
	return 0;
}