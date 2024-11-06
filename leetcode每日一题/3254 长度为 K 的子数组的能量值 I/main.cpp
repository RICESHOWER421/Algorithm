#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int count = 0;
        for (int i = 1; i < k; i++) {
            if (nums[i] > nums[i - 1]) ++count;
        }
        if (count == k - 1) ans.push_back(nums[k - 1]);
        else {
            ans.push_back(-1);
            count = 0;
        }

        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                ++count;
                if (count == k) ans.push_back(nums[i]);
                else ans.push_back(-1);
            }
            else {
                count = 0;
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = { 1,2,3,4,3,2,5 };
    vector<int> ans = Solution().resultsArray(nums, 3);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}