#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) return nums;

        vector<int> ans;
        int count = 0;
        for (int i = 1; i < k; i++) {
            if (nums[i] > nums[i - 1] && nums[i] == nums[i - 1] + 1) ++count;
            else count = 0;
        }

        if (count == k - 1) ans.push_back(nums[k - 1]);
        else ans.push_back(-1);

        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1] && nums[i] == nums[i - 1] + 1) {
                ++count;
                if (count >= k - 1) ans.push_back(nums[i]);
                else ans.push_back(-1);
            }
            else {
                ans.push_back(-1);
                count = 0;
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}