#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, int> hash_map;
        int ans = -1;
        for (int i = 0; i < (int)nums.size(); i++) {
            int sum = 0;
            int ret = nums[i];
            while (ret) {
                sum += (ret % 10);
                ret /= 10;
            }
            if (i && hash_map.count(sum)) ans = max(nums[i] + hash_map[sum], ans);
            hash_map[sum] = (hash_map.count(sum) ? max(nums[i], hash_map[sum]) : nums[i]);
        }
        return ans;
    }
};

int main() {

	return 0;
}