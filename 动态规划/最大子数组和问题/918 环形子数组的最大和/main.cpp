#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);
        auto g = f;

        int sum = 0, f_max = INT_MIN, g_min = INT_MAX;
        for (int i = 1; i <= n; i++) {
            sum += nums[i - 1];
            f[i] = max(nums[i - 1], f[i - 1] + nums[i - 1]);
            f_max = max(f[i], f_max);

            g[i] = min(g[i - 1] + nums[i - 1], nums[i - 1]);
            g_min = min(g_min, g[i]);
        }

        if (sum == g_min) return f_max;
        else return max(f_max, sum - g_min);
    }
};

int main() {

	return 0;
}