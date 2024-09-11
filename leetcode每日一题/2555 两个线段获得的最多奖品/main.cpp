#include <iostream>
#include <vector>
#include <map>
using namespace std;

int maximizeWin(vector<int>& prizePositions, int k) {
    int n = prizePositions.size();
    if (k * 2 + 1 >= prizePositions.back() - prizePositions[0]) return n;   //这种情况下可以拿到全部奖品

    int ans = 0, left = 0;
    vector<int> dp(n + 1);
    for (int right = 0; right < n; right++) {
        while (prizePositions[right] - prizePositions[left] > k) ++left;
        ans = max(ans, dp[left] + right - left + 1);
        dp[right + 1] = max(dp[right], right - left + 1);
    }
    return ans;
}

int main() {
    vector<int> prizePositions = { 1,1,2,2,2,3,3,3,4,4,4,5,5,5,9,9,9,11,11,11,13,13,14,19,20,22,22,22,22 };
    int k = 7;
    cout << maximizeWin(prizePositions, k) << endl;
	return 0;
}