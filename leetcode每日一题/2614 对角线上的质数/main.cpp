#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        auto isprime = [&](int num) -> bool {
            if (num == 1) {
                return false;
            }

            for (int i = 2; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    return false;
                }
            }
            return true;
        };

        int m = nums.size(), ans = 0;
        for (int i = 0; i < m; i++) {
            if (isprime(nums[i][i])) {
                ans = max(ans, nums[i][i]);
            }
            if (isprime(nums[i][m - i - 1])) {
                ans = max(ans, nums[i][m - i - 1]);
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> nums = { {1,2,3}, {4,5,6}, {7,8,9} };
    cout << Solution().diagonalPrime(nums) << "\n";
	return 0;
}