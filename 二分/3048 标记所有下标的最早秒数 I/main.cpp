#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int left = 1, right = changeIndices.size() + 1;

        int n = nums.size();
        vector<int> hash_map(2001);
        for (int i = 0; i < changeIndices.size(); i++) changeIndices[i]--;
        for (int i = 0; i < n; i++) hash_map[i] = nums[i];

        while (left < right) {
            int mid = (left + right) / 2;
            vector<pair<int, int>> nums(n, {-1,-1});
            for (int i = 0; i < mid; i++) {
                nums[changeIndices[i]].first = changeIndices[i];
                nums[changeIndices[i]].second = max(nums[changeIndices[i]].second, i);
            }

            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (nums[i].first == -1) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                sort(nums.begin(), nums.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
                    return a.second < b.second;
                });

                int count = nums[0].second, cur = 0;
                while (cur < nums.size()) {
                    if (count < hash_map[nums[cur].first]) {
                        ok = false;
                        break;
                    }
                    else {
                        count -= hash_map[nums[cur].first];
                        ++cur;
                        if(cur < nums.size()) count += nums[cur].second - nums[cur - 1].second - 1;
                    }
                }

                if (ok) right = mid;
                else left = mid + 1;
            }
            else left = mid + 1;
        }
        return left == changeIndices.size() + 1 ? -1 : left;
    }
};

int main() {
    vector<int> nums = { 1,3 }, changeIndices = {1,1,1,2,1,1,1};
    cout << Solution().earliestSecondToMarkIndices(nums, changeIndices) << "\n";
	return 0;
}