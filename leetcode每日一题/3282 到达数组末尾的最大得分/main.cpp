#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        int cur = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= nums[cur] && i != nums.size() - 1) {
                ans += (long long)nums[cur] * (i - cur);
                cur = i;
            }
        }
        ans += (long long)nums[cur] * (nums.size() - 1 - cur);
        return ans;
    }
};

int main() {

	return 0;
}