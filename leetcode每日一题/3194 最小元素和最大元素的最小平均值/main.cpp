#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1;
        double ans = 1e5;
        while (left < right) {
            ans = min(ans, ((double)nums[left] + nums[right]) / 2);
            ++left;
            --right;
        }
        return ans;
    }
};

int main() {

	return 0;
}