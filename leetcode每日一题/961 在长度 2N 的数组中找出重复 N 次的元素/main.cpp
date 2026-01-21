#include <bits/stdc++.h>
using namespace std;

//哈希
//class Solution {
//public:
//    int repeatedNTimes(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> hash_map(10001);
//        for (auto& x : nums) {
//            hash_map[x]++;
//            if (hash_map[x] == n / 2) return x;
//        }
//        return -1;
//    }
//};

//空间复杂度优化为O(1) 摩尔投票
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int ans = 0, hp = 0, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[0]) return nums[0]; 
            if (!hp) {  //hp为0，nums[i]成为新擂主
                ans = nums[i];
                hp = 1;
            }
            else {  //hp仍然存在，与ans相同+1，反之-1
                hp += nums[i] == ans ? 1 : -1;
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}