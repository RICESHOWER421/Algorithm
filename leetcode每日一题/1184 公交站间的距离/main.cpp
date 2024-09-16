#include <iostream>
#include <vector>
using namespace std;

int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    int n = distance.size();
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + distance[i - 1];
    }

    if (start > destination) swap(start, destination);
    return min(dp[destination] - dp[start], dp[n] - (dp[destination] - dp[start]));
}

int main() {

	return 0;
}