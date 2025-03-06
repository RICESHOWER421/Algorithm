#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        vector<int> path;
        map<int, int> hash_map;
        auto dfs = [&](auto&& dfs, int pos) -> void {
            for (auto& x : path) {
                if (hash_map[x + k] || hash_map[x - k]) {
                    return;
                }
            }

            ++ans;
            if (pos == n) {
                return;
            }

            for (int i = pos; i < n; i++) {
                path.push_back(nums[i]);
                hash_map[nums[i]]++;
                dfs(dfs, i + 1);
                path.pop_back();
                hash_map[nums[i]]--;
            }
        };

        dfs(dfs, 0);
        return ans - 1;
    }
};

int main() {
    vector<int> nums = { 1,1,2,3 };
    int k = 1;
    cout << Solution().beautifulSubsets(nums, k) << "\n";
	return 0;
}