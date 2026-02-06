#include <bits/stdc++.h>
using namespace std;

//排序 + 二分
//class Solution {
//public:
//    using ll = long long;
//    int minRemoval(vector<int>& nums, int k) {
//        sort(nums.begin(), nums.end());
//        int ans = 1e5 + 10, n = nums.size();
//        for (int i = 0, cnt = 0; i < n; i++, cnt++) {
//            if (ans <= cnt) break;
//            ll tmp = nums[i] * k;
//            int l = i, r = n - 1;
//            while (l < r) {
//                int mid = l + (r - l + 1) / 2;
//                if (nums[mid] <= tmp) l = mid;
//                else r = mid - 1;
//            }
//            ans = min(ans, cnt + n - l);
//        }
//        return ans;
//    }
//};

//排序 + 滑动窗口
class Solution {
public:
    using ll = long long;
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0, n = nums.size(), ans = 1e5 + 10;
        while (r < n) {
            while (r < n && nums[r] <= (ll)nums[l] * k) ++r;
            ans = min(ans, n - (r - l));
            ++l;
        }
        return ans;
    }
};


int main() {

	return 0;
}