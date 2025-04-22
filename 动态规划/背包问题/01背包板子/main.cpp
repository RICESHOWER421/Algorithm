#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//没有对空间进行优化
//int main() {
//	int n = 0, v = 0;
//	cin >> n >> v;
//	vector<pair<int, int>> nums(n + 1);
//	for (int i = 1; i <= n; i++) cin >> nums[i].first >> nums[i].second;
//
//	//dp1[i][j]表示选取前i个物体，体积不超过j的最大价值
//	vector<vector<int>> dp1(n + 1, vector<int>(v + 1));
//	//dp2[i][j]表示选取前i个物体，体积正好为j的最大价值
//	vector<vector<int>> dp2(n + 1, vector<int>(v + 1));
//	int max_num = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= v; j++) {
//			dp1[i][j] = max(dp1[i - 1][j], (j - nums[i].first >= 0 ? dp1[i - 1][j - nums[i].first] + nums[i].second : 0));
//			if (j - nums[i].first > 0 && dp2[i - 1][j - nums[i].first]) dp2[i][j] = dp2[i - 1][j - nums[i].first] + nums[i].second;
//			else if (j - nums[i].first == 0) dp2[i][j] = nums[i].second;
//			dp2[i][j] = max(dp2[i - 1][j], dp2[i][j]);
//		}
//	}
//
//	cout << dp1[n][v] << endl;
//	cout << dp2[n][v] << endl;
//
//	return 0;
//}

//对空间进行优化
int main() {
	int n = 0, v = 0;
	cin >> n >> v;
	vector<pair<int, int>> nums(n + 1);
	for (int i = 1; i <= n; i++) cin >> nums[i].first >> nums[i].second;

	int N = max(n, v) + 1;
	//dp1[i][j]表示选取前i个物体，体积不超过j的最大价值
	vector<int> dp1(N);
	//dp2[i][j]表示选取前i个物体，体积正好为j的最大价值
	vector<int> dp2(N);
	int max_num = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = v; j >= nums[i].first; j--) {
			dp1[j] = max(dp1[j], dp1[j - nums[i].first] + nums[i].second);
			int temp = 0;
			if (j - nums[i].first > 0 && dp2[j - nums[i].first]) temp = dp2[j - nums[i].first] + nums[i].second;
			else if (j - nums[i].first == 0) temp = nums[i].second;
			dp2[j] = max(dp2[j], temp);
		}
	}

	cout << dp1[v] << endl;
	cout << dp2[v] << endl;

	return 0;
}