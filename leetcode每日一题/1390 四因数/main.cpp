#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int sum = 1 + nums[i], cnt = 0;
            for (int j = 2; j <= sqrt(nums[i]); j++) {
                if (nums[i] % j == 0) {
                    sum += (nums[i] / j + j);
                    if (j == sqrt(nums[i])) ++cnt;
                    else cnt += 2;
                    if (cnt > 2) break;
                }
            }
            if (cnt == 2) ans += sum;
        }
        return ans;
    }
};

int main() {

	return 0;
}