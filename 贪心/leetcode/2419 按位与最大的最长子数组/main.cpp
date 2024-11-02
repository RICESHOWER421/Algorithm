#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ret = -1;
        for (auto& x : nums) {
            ret = max(x, ret);
        }

        int ans = 0, sum = 0;
        for (auto& x : nums) {
            if (x == ret) {
                ++sum;
            }
            else {
                ans = max(ans, sum);
                sum = 0;
            }
        }
        return max(ans, sum);
    }
};

int main() {

	return 0;
}