#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    long long countGood(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size();
        ll sum = 0, ans = 0;
        map<int, int> hash_map;
        while (r < n) {
            hash_map[nums[r]]++;
            sum += (hash_map[nums[r]] - 1);
            while (sum >= k) {
                ans += (n - r);
                sum -= (hash_map[nums[l]] - 1);
                hash_map[nums[l]]--;
                ++l;
            }
            ++r;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = { 1,1,1,1,1 };
    cout << Solution().countGood(nums, 10) << "\n";
	return 0;
}