#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = abs(nums[0] - nums[1]);
        for (int i = 0; i < nums.size() - 1; i++) {
            ans = max(ans, abs(nums[i] - nums[i + 1]));
        }
        return max(ans, abs(nums[0] - nums.back()));
    }
};

int main() {

	return 0;
}