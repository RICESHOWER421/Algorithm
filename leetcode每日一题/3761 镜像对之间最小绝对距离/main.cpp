#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size(), ans = n;
        unordered_map<int, int> hash_map;
        for (int i = n - 1; i >= 0; i--) {
            string tmp = to_string(nums[i]);
            reverse(tmp.begin(), tmp.end());
            int num = atoi(tmp.c_str());
            if (hash_map.find(num) != hash_map.end()) ans = min(ans, hash_map[num] - i);

            //判断完成之后才能更改信息
            hash_map[nums[i]] = i;
        }
        return ans == n ? -1 : ans;
    }
};

int main() {

	return 0;
}