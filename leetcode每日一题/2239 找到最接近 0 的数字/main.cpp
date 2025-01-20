#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = nums[0];
        for (auto& x : nums) {
            if (abs(x) < abs(ans)) {
                ans = x;
            }
            else if (abs(x) == abs(ans)) {
                if (x > ans) {
                    ans = x;
                }
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}