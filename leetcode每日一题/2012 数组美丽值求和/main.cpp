#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> mxs(n), mns(n);
        mxs[0] = nums[0], mns.back() = nums.back();
        for (int i = 1; i < n; i++) {
            mxs[i] = max(nums[i], mxs[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            mns[i] = min(nums[i], mns[i + 1]);
        }

        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > mxs[i - 1] && nums[i] < mns[i + 1]) {
                ans += 2;
            }
            else if (nums[i] > nums[i - 1] && nums[i + 1] > nums[i]) {
                ++ans;
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}