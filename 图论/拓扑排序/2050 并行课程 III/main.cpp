#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

class Solution {
public:
	int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
		vector<vector<int>> g(n + 1);
		vector<int> cnts(n + 1);
		for (auto& x : relations) {
			g[x[0]].push_back(x[1]);
			cnts[x[1]]++;
		}

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (!cnts[i]) q.push(i);
		}

		vector<int> dp(n + 1);	//dp[i]表示第i门课程完成所需要的最少时间 
		while (!q.empty()) {
			int pos = q.front();
			q.pop();
			dp[pos] += time[pos - 1];
			for (auto& x : g[pos]) {
				dp[x] = max(dp[pos], dp[x]);
				cnts[x]--;
				if (!cnts[x]) q.push(x);
			}
		}

		int ans = 0;
		for (auto& x : dp) {
			ans = max(x, ans);
		}
		return ans;
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	return 0;
}