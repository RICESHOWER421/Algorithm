#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//最长递增子序列类似题
//动态规划超时写法
//int maxEnvelopes(vector<vector<int>>& envelopes) {
//	sort(envelopes.begin(), envelopes.end());
//
//	vector<int> dp(envelopes.size(), 1);
//	int max_num = 1;
//	for (int i = 1; i < envelopes.size(); i++) {
//		for (int j = 0; j < i; j++) {
//			if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
//				dp[i] = max(dp[j] + 1, dp[i]);
//				max_num = max(max_num, dp[i]);
//			}
//		}
//	}
//	return max_num;
//}

//解法二：重构排序 + 贪心 + 二分
int maxEnvelopes(vector<vector<int>>& envelopes) {
	sort(envelopes.begin(), envelopes.end(), [](const vector<int>& s1, const vector<int>& s2) {
		return s1[0] != s2[0] ? s1[0] < s2[0] : s1[1] > s2[1];
	});

	vector<int> ret;
	ret.push_back(envelopes[0][1]);
	for (int i = 1; i < envelopes.size(); i++) {
		if (envelopes[i][1] > ret.back()) ret.push_back(envelopes[i][1]);
		else {
			int left = 0, right = ret.size() - 1;
			while (left < right) {
				int mid = left + (right - left) / 2;
				if (ret[mid] >= envelopes[i][1]) right = mid;
				else left = mid + 1;
			}
			ret[left] = envelopes[i][1];
		}
	}
	return ret.size();
}

int main() {
	vector<vector<int>> envelopes = { {2,1},{3,2},{5,3},{6,5} ,{8,10}, {10,4} };
	cout << maxEnvelopes(envelopes) << endl;
	return 0;
}