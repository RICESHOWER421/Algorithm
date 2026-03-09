#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<ll>>> memo(zero + 1, vector<vector<ll>>(one + 1, vector<ll>(2, -1)));
        auto dfs = [&](auto&& dfs, int i, int j, int k)->ll {  //dfs(i,j,k)表示存在i个0和j个1时，第i+j个数填k时的稳定二进制数组
            if (i == 0) {     //0正好用完
                return k == 1 && j <= limit;
            }
            if (j == 0) {     //1正好用完
                return k == 0 && i <= limit;
            }

            auto& tmp = memo[i][j][k];
            if (tmp != -1) return memo[i][j][k];

            if (k == 0) {     //如果最后一个数是0 (+MOD是为了防止负数出现)，最后的dfs(dfs, i - limit - 1, j, 1)实际上是dfs(dfs, i - 1, j, 0)中不合法的一部分
                tmp = (dfs(dfs, i - 1, j, 0) + dfs(dfs, i - 1, j, 1) + (i > limit ? MOD - dfs(dfs, i - limit - 1, j, 1) : 0)) % MOD;
            }
            else {
                tmp = (dfs(dfs, i, j - 1, 0) + dfs(dfs, i, j - 1, 1) + (j > limit ? MOD - dfs(dfs, i, j - limit - 1, 0) : 0)) % MOD;
            }
            return tmp;
        };
        return (dfs(dfs, zero, one, 0) + dfs(dfs, zero, one, 1)) % MOD;
    }
};

/*
limit = 3
10
100
1000
*/

int main() {

	return 0;
}