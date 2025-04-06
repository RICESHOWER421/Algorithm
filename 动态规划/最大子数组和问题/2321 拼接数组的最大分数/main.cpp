#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int s1 = 0, s2 = 0;
        for (auto& x : nums1) {
            s1 += x;
        }
        for (auto& x : nums2) {
            s2 += x;
        }

        int ans = max(s1, s2), r1 = 0, r2 = 0;
        for (int i = 0; i < nums1.size(); i++) {
            r1 = nums2[i] - nums1[i] + max(r1, 0);
            r2 = nums1[i] - nums2[i] + max(r2, 0);
            ans = max(ans, max(r1 + s1, r2 + s2));
        }
        return ans;
    }
};


int main() {
    vector<int> nums1 = { 312,3,123,2,423,43,53,45,4,65,7,578,67,87,6897 }, nums2 = { 3123,123,3454,645,423,123,4235,645,7568,345,123,432,123,1,2 };
    cout << Solution().maximumsSplicedArray(nums1, nums2) << "\n";
	return 0;
}