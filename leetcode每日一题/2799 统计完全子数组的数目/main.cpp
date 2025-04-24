#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s;
        for (auto& x : nums) {
            s.insert(x);
        }

        int l = 0, r = 0, ans = 0, cnt = 0;
        vector<int> hash_map(2001);
        while (r < nums.size()) {
            if (hash_map[nums[r]] == 0) {
                ++cnt;
            }
            hash_map[nums[r]]++;
            while (cnt == s.size()) {
                ans += nums.size() - r;
                hash_map[nums[l]]--;
                if (hash_map[nums[l]] == 0) {
                    --cnt;
                }
                ++l;
            }
            ++r;
        }
        return ans;
    }
};

int main() {

	return 0;
}