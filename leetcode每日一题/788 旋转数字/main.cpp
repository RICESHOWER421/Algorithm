#include <bits/stdc++.h>
using namespace std;

//暴力枚举解法
class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int num = i;
            bool ok = false;
            while (num) {
                int x = num % 10;
                if (x == 2 || x == 5 || x == 6 || x == 9) {
                    ok = true;
                }
                else if (x == 3 || x == 4 || x == 7) {
                    ok = false;
                    break;
                }
                num /= 10;
            }
            ans += ok;
        }
        return ans;
    }
};

//数位dp解法
class Solution {
public:
    int rotatedDigits(int n) {
        string high = to_string(n);
        string low = "1";
        int len = high.size();
        low = string(len - low.size(), '0') + low;
        vector<vector<int>> memo(len, vector<int>(2, -1));

        auto dfs = [&](auto&& dfs, int i, bool ok, bool limit_low, bool limit_high)->int {
            if (i == len) return ok;
            if (!limit_low && !limit_high && memo[i][ok] != -1) return memo[i][ok];

            int lo = limit_low ? low[i] - '0' : 0;
            int hi = limit_high ? high[i] - '0' : 9;

            int ans = 0;
            for (int d = lo; d <= hi; d++) {
                if (d != 3 && d != 4 && d != 7) {
                    ans += dfs(dfs, i + 1, ok || (d == 2 || d == 5 || d == 6 || d == 9), limit_low && d == lo, limit_high && d == hi);
                }
            }
            if (!limit_high && !limit_low) memo[i][ok] = ans;
            return ans;
        };
        return dfs(dfs, 0, false, true, true);
    }
};
int main() {

	return 0;
}