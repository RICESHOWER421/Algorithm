#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> nums(32);
        for (auto& x : candidates) {
            for (int i = 0; i < 32; i++) {
                nums[i] += x & 1;
                x >>= 1;
            }
        }

        int ans = 0;
        for (auto& x : nums) {
            ans = max(x, ans);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = { 16,17,71,62,12,24,14 };
    cout << Solution().largestCombination(nums) << "\n";
	return 0;
}