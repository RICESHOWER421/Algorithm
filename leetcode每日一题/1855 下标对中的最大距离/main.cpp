#include <bits/stdc++.h>
using namespace std;

//二分写法
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), ans = 0;
        auto check = [&](int l, int num)->int {  //找出第一个nums2[idx] < nums1[i]
            int r = m;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (nums2[mid] >= num) l = mid + 1;
                else r = mid;
            }
            return l;
        };
        for (int i = 0; i < min(n, m); i++) {
            int idx = check(i, nums1[i]) - 1;
            if (idx >= i) ans = max(ans, idx - i);
        }
        return ans;
    }
};

//双指针写法
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), l = 0, r = 0, ans = 0;
        while (l < n && r < m) {
            while (l > r || r < m && nums1[l] <= nums2[r]) ++r;
            if (l <= r - 1) ans = max(ans, r - 1 - l);
            ++l;
        }
        return ans;
    }
};

int main() {

	return 0;
}