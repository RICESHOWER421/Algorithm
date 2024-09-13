#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
	int ans = -1;
	int n = chargeTimes.size();
	long long sum = 0;

	vector<long long> dp(n + 1);
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + runningCosts[i - 1];
	}

	deque<int> dq;
	int left = 0, right = 0;
	while (right < n)
	{
		while (!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[right]) {
			dq.pop_back();
		}
		dq.push_back(right);

		sum = chargeTimes[dq.front()] + (long long)(right - left + 1) * (dp[right + 1] - dp[left]);

		while (sum > budget)
		{
			if (!dq.empty() && left == dq.front()) {
				dq.pop_front();
			}
			++left;
			if (dq.empty()) break;
			sum = (chargeTimes[dq.front()] + (long long)(right - left + 1) * (dp[right + 1] - dp[left]));
		}
		ans = max(right - left + 1, ans);
		++right;
	}

	return ans == -1 ? 0 : ans;
}

int main() {
	vector<int> chargeTimes = { 11,12,19 };
	vector<int> runningCosts = { 10,8,7 };
	long long budget = 19;
	cout << maximumRobots(chargeTimes, runningCosts, budget) << endl;
	return 0;
}