#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> hash_map(10001, -1),st, ans(n1);
        st.push_back(nums2.back());
        for (int i = n2 - 2; i >= 0; i--) {
            while (!st.empty() && nums2[i] > st.back()) st.pop_back();
            if (!st.empty()) hash_map[nums2[i]] = st.back();
            st.push_back(nums2[i]);
        }
        for (int i = 0; i < n1; i++) {
            ans[i] = hash_map[nums1[i]];
        }
        return ans;
    }
};

int main() {
    vector<int> n1 = { 2,4 }, n2 = { 1,2,3,4 };
    vector<int> ans = Solution().nextGreaterElement(n1,n2);
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << "\n";
	return 0;
}