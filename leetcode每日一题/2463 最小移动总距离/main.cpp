#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    const ll MX = 1e15;
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = factory.size(), m = robot.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        //dp[i][j]表示[0,i]下标位置的工厂修理[0,j]下标位置的机器人所能得到的最小化机器人总距离
        //之所以这么设置状态是因为运用到了贪心，我们所能得到的最小化机器人总距离一定是每个工厂和若干个靠近它的机器人之间的距离之和
        vector<vector<ll>> memo(n, vector<ll>(m, -1));
        auto dfs = [&](auto&& dfs, int i, int j)->ll {
            if (j < 0) return 0;     //机器人修完了
            if (i < 0) return MX;    //工厂没有了，机器人没修完
            if (memo[i][j] != -1) return memo[i][j];

            memo[i][j] = dfs(dfs, i - 1, j);   //该工厂不修机器人
            ll sum = 0;
            for (int k = 1; k <= min(factory[i][1], j + 1); k++) {
                sum += abs(robot[j - k + 1] - factory[i][0]);
                memo[i][j] = min(memo[i][j], dfs(dfs, i - 1, j - k) + sum);
            }
            return memo[i][j];
        };
        return dfs(dfs, n - 1, m - 1);
    }
};


int main() {
    vector<int> robot = { 9,11,99,101 };
    vector<vector<int>> factory = { {10,1},{7,1},{14,1},{100,1},{96,1},{103,1} };
    cout << Solution().minimumTotalDistance(robot, factory) << "\n";
    return 0;
}