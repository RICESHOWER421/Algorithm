#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int, int> hash_map;
        vector<int> nums, ans;
        for (auto& x : items) {
            if (!hash_map.count(x[0])) {
                nums.push_back(x[0]);
                hash_map[x[0]] = x[1];
            }
            else {
                hash_map[x[0]] = max(hash_map[x[0]], x[1]);
            }
        }

        sort(nums.begin(), nums.end());
        vector<int> rets(nums.size());
        rets[0] = hash_map[nums[0]];
        for (int i = 1; i < rets.size(); i++) {
            rets[i] = max(hash_map[nums[i]], rets[i - 1]);
        }

        for (auto& x : queries) {
            int l = 0, r = rets.size() - 1;
            while (l < r) {
                int mid = l + (r - l + 1) / 2;
                if (nums[mid] <= x) {
                    l = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            ans.push_back(l == 0 && nums[l] > x ? 0 : rets[l]);
        }
        return ans;
    }
};

int main() {

	return 0;
}