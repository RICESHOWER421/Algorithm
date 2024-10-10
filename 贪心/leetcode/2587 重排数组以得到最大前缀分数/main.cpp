#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int ans = 0;
        long long sum = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i];
            if (sum <= 0) break;
            ++ans;
        }
        return ans;
    }
};

int main() {

	return 0;
}