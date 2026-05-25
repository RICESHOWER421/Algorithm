#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[1] = 1;

        for (int i = 1; i < n; i++) {
            dp[i + 1] = dp[i];
            if (i >= minJump && s[i] == '0' && dp[i - minJump + 1] > dp[max(i - maxJump, 0)]) dp[i + 1]++;
        }
        return dp[n] > dp[n - 1];
    }
};

int main() {

	return 0;
}