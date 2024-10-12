#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int ans_function(vector<int>& nums1, vector<int>& nums2, int sum_1, int sum_2) {
        int ans = 0;
        int left = 0, right = nums2.size() - 1;
        while (sum_1 < sum_2 && (left < (int)nums1.size() || right >= 0)) {
            ++ans;
            int first = -1, second = -1;
            if (left < (int)nums1.size()) first = 6 - nums1[left];
            if (right >= 0) second = nums2[right] - 1;

            if (first >= second || right < 0) {
                sum_1 += first;
                ++left;
            }
            else {
                sum_2 -= second;
                --right;
            }
        }
        return sum_1 >= sum_2 ? ans : -1;
    }

    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum_1 = 0, sum_2 = 0;
        for (auto& x : nums1) sum_1 += x;
        for (auto& x : nums2) sum_2 += x;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        //sum值大的要将元素大小拉小，sum值小的元素要将元素大小拉大
        int ans = 0;
        if (sum_1 < sum_2) ans = ans_function(nums1, nums2, sum_1, sum_2);
        else if (sum_1 > sum_2) ans = ans_function(nums2, nums1, sum_2, sum_1);
        return ans;
    }
};

int main() {
    vector<int> nums1 = { 1,3,2,4,5,6};
    vector<int> nums2 = { 6,5,4,3,2,1};
    cout << Solution().minOperations(nums1, nums2) << endl;
	return 0;
}