#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    using ll = long long;
    ll my_pow(ll a, ll b) {
        ll base = a % MOD, ans = 1;
        while (b) {
            if (b % 2) {
                ans = ans * base % MOD;
            }
            base = base * base % MOD;
            b /= 2;
        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        ll ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());

        auto check = [&](int num)->int {
            if (num <= 1) return -1;
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = l + (r - l + 1) / 2;
                if (nums[mid] < num) l = mid;
                else r = mid - 1;
            }
            return r;
        };

        for (int i = 0; i < n; i++) {
            int pos = check(target - nums[i] + 1);
            if (pos != -1) {
                if (nums[pos] == target - nums[i] + 1) --pos;
            }
            if (pos == -1 || pos < i) break;
            ll tmp = pos - i;
            ans = (ans + my_pow(2, tmp)) % MOD;
        }
        return ans;
    }
};

int main() {

	return 0;
}