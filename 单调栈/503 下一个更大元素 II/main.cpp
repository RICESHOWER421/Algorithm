#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1), st;
        st.push_back(nums.back());
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && nums[i] >= st.back()) st.pop_back();
            if (!st.empty()) ans[i] = st.back();
            st.push_back(nums[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] >= st.back()) st.pop_back();
            if (!st.empty()) ans[i] = st.back();
            st.push_back(nums[i]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,2,1};
    vector<int> ans = Solution().nextGreaterElements(nums);
    for (auto& x : ans) cout << x << " ";
    cout << "\n";
	return 0;
}