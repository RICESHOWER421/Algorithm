#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash_map(101);
        bool ok = true;
        for (auto& x : nums) {
            hash_map[x]++;
            if (hash_map[x] > 1) {
                ok = false;
            }
        }

        if (ok) {
            return 0;
        }
        int ret = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            hash_map[nums[i]]--;
            ++ret;
            if (ret == 3) {
                ++ans;
                bool tmp = true;
                for (int j = i + 1; j < n; j++) {
                    if (hash_map[nums[j]] > 1) {
                        tmp = false;
                        break;
                    }
                }
                if (tmp) {
                    return ans;
                }
                ret = 0;
            }
        }
        return ans + (ret != 0);
    }
};

int main() {

	return 0;
}