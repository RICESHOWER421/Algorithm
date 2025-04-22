#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
	vector<pair<int, int>> count;
	for (int i = 0; i < strs.size(); i++) {
		int num0 = 0, num1 = 0;
		for (auto x : strs[i]) {
			if (x == '1') ++num1;
			else ++num0;
		}
		count.push_back({num0, num1});
	}

	//dp[i][j][k]表示从前i种字符串中任意挑选，其0的数量不超过j，1的数量不超过k的最大长度
	vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
	for (int i = 1; i <= strs.size(); i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= n; k++)
				dp[i][j][k] = max(dp[i - 1][j][k], (j >= count[i - 1].first && k >= count[i - 1].second ? dp[i - 1][j - count[i - 1].first][k - count[i - 1].second] + 1 : 0));
	return dp[strs.size()][m][n];
}

int main() {
	vector<string> strs = { "10", "0001", "111001", "1", "0" };
	int m = 5, n = 3;
	cout << findMaxForm(strs, m, n) << endl;
	return 0;
}