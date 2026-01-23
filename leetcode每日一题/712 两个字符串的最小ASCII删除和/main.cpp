#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int minimumDeleteSum(string s1, string s2) {
	int m = s1.size(), n = s2.size();
	//dp[i][j]表示字符串s1区间[0, i]和字符串s2区间[0, j]的最大子序列ASCII值
	vector<vector<int>>dp(m + 1, vector<int>(n + 1));
	int sum_s1 = 0, sum_s2 = 0;
	for (int i = 0; i < m; i++) sum_s1 += s1[i];
	for (int j = 0; j < n; j++) sum_s2 += s2[j];
	s1 = " " + s1, s2 = " " + s2;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = max((s1[i] == s2[j] ? dp[i - 1][j - 1] + s1[i] : 0), max(dp[i - 1][j], dp[i][j - 1]));
		}
	}

	return sum_s1 + sum_s2 - 2 * dp[m][n];
}
int main() {
	
	return 0;
}