#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0, n = nums.size(), pre = 0;
        for (int i = 0; i < n; i++) {
            sum += i * nums[i];
            pre += nums[i];
        }

        int ans = sum;
        for (int i = n - 1; i > 0; i--) {
            ans = max(ans, sum + pre - nums[i] * n);
            sum += pre - nums[i] * n;
        }
        return ans;
    }
};

int main() {

	return 0;
}