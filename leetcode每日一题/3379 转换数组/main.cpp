#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int ret = abs(nums[i]) % n;
            if (nums[i] > 0) ans[i] = nums[(i + ret) % n];
            else if (nums[i] < 0) ans[i] = nums[(i + n - ret) % n];
            else ans[i] = nums[i];
        }
        return ans;
    }
};

int main() {

	return 0;
}