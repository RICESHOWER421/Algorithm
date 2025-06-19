#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        int ret = nums[0];
        for (int i = 0; i < n; i++) {
            if (nums[i] - ret > k) {
                ret = nums[i];
                ++ans;
            }
        }
        return ans + 1;
    }
};

int main() {

	return 0;
}