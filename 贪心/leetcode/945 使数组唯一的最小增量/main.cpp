#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        map<int, int> hash_map;
        hash_map[nums[0]] = 1;
        int ans = 0;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (hash_map.count(nums[i])) {
                ans += (nums[i - 1] + 1 - nums[i]);
                nums[i] = nums[i - 1] + 1;
            }
            hash_map[nums[i]] = 1;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = { 3,2,1,2,1,7 };
    cout << Solution().minIncrementForUnique(nums) << endl;
	return 0;
}