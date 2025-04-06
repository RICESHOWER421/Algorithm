#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);
        auto g = f;
        int return_num = INT_MIN;
        f[0] = g[0] = 1;

        for (int i = 1; i <= n; i++) {
            g[i] = min(nums[i - 1], min(g[i - 1] * nums[i - 1], f[i - 1] * nums[i - 1]));
            f[i] = max(nums[i - 1], max(g[i - 1] * nums[i - 1], f[i - 1] * nums[i - 1]));
            return_num = max(return_num, f[i]);
        }

        return return_num;
    }
};

int main() {

	return 0;
}