#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;
    long long fast_power(long long a, long long b, long long p) {
        long long result = 1;
        // 先对底数取模，避免后续计算溢出
        long long base = a % p;

        while (b > 0) {
            // 如果当前位为 1
            if (b % 2 == 1) {
                result = (result * base) % p;
            }
            // 更新 base
            base = (base * base) % p;
            // 将 b 右移一位
            b /= 2;
        }
        return result;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), B = sqrt(queries.size());
        vector<vector<ll>> diff(B);    //差分数组，B为阈值，进行情况划分
        for (auto& x : queries) {
            int l = x[0], r = x[1], k = x[2];
            ll v = x[3];
            if (k < B) {
                if (diff[k].empty()) {
                    diff[k].resize(n + k, 1);
                }
                diff[k][l] = diff[k][l] * v % MOD;
                r = r - (r - l) % k + k;
                diff[k][r] = diff[k][r] * fast_power(v, MOD - 2, MOD) % MOD;
            }
            else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = nums[i] * v % MOD;
                }
            }
        }

        //处理差分数组
        for (int i = 1; i < B; i++) {
            if (diff[i].empty()) continue;
            for (int j = 0; j < i; j++) {
                ll tmp = 1;
                for (int k = j; k < n; k += i) {
                    tmp = tmp * diff[i][k] % MOD;
                    nums[k] = nums[k] * tmp % MOD;
                }
            }
        }

        int ans = 0;
        for (auto& x : nums) {
            ans ^= x;
        }
        return ans;
    }
};

int main() {

	return 0;
}