#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto& x : queries) {
            int l = x[0], r = x[1], k = x[2], v = x[3];
            for (int i = l; i <= r; i += k) {
                nums[i] = (long long)nums[i] * v % MOD;
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