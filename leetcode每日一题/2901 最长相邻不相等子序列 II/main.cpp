#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);   //dp[i]表示选第i个字符串为初始位置时所能获得的最长子序列
        vector<vector<string>> ans(n);
        auto check = [&](string& a, string& b)->bool {
            if (a.size() != b.size()) return false;
            int cnt = 0;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != b[i]) ++cnt;
                if (cnt > 1) return false;
            }
            return cnt == 1;
        };

        for (int i = n - 1; i >= 0; i--) {
            int pos = -1;
            ans[i].push_back(words[i]);
            for (int j = i + 1; j < n; j++) {
                if (groups[i] != groups[j] && check(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pos = j;
                }
            }
            if (pos != -1) {
                for (auto& x : ans[pos]) {
                    ans[i].push_back(x);
                }
            }
        }

        int pos = 0, sum = dp[0];
        for (int i = 0; i < n; i++) {
            if (dp[i] > sum) {
                sum = dp[i];
                pos = i;
            }
        }
        return ans[pos];
    }
};

int main() {
    vector<string> rets = { "bab","dab","cab" };
    vector<int> groups = {1,2,2};
    vector<string> ans = Solution().getWordsInLongestSubsequence(rets, groups);
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << "\n";
	return 0;
}