#include <iostream>
#include <vector>
using namespace std;

//对应leetcode 121 122 123 188 309 714
//买卖股票的最佳时机
int maxProfit(vector<int>& prices) {
    int cost = INT_MAX, profit = 0;
    for (int i = 0; i < prices.size(); i++) {
        cost = min(cost, prices[i]);
        profit = max(prices[i] - cost, profit);
    }

    return profit;
}

//买卖股票的最佳时机II
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][1] = -prices[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }

    return dp[n - 1][0];
}

//买卖股票的最佳时机III
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> g(n, vector<int>(3, -0x3f3f3f3f));
    auto f = g;
    f[0][0] = -prices[0];
    g[0][0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
            g[i][j] = g[i - 1][j];
            if (j >= 1) g[i][j] = max(g[i - 1][j], f[i - 1][j - 1] + prices[i]);
        }
    }

    return max(g[n - 1][0], max(g[n - 1][1], g[n - 1][2]));
}

//买卖股票的最佳时机IV
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> g(n, vector<int>(k + 1, -0x3f3f3f3f));
    auto f = g;
    f[0][0] = -prices[0];
    g[0][0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
            g[i][j] = g[i - 1][j];
            if (j >= 1) g[i][j] = max(g[i - 1][j], f[i - 1][j - 1] + prices[i]);
        }
    }

    int max_num = 0;
    for (int i = 0; i <= k; i++) {
        max_num = max(max_num, g[n - 1][i]);
    }
    return max_num;
}

//买卖股票的最佳时机含冷冻期
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = -prices[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][2] = dp[i - 1][0] + prices[i];
    }

    return max(dp[n - 1][1], dp[n - 1][2]);
}

//买卖股票的最佳时机含手续费
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][1] = -prices[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }

    return dp[n - 1][0];
}

int main() {

	return 0;
}