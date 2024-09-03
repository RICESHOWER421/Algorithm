#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//排序方法，时间复杂度为O(NlogN)
//long long maxStrength(vector<int>& nums) {
//    vector<int> nums1, nums2;
//    int ret = 0;    //判断是否存在0
//    for (int i = 0; i < nums.size(); i++) {
//        if (nums[i] > 0) nums1.push_back(nums[i]);
//        else if (nums[i] < 0) nums2.push_back(nums[i]);
//        else ret = 1;
//    }
//
//    sort(nums2.begin(), nums2.end());
//    long long ans = 1;
//    for (int i = 0; i < nums1.size(); i++) ans *= nums1[i];
//
//    int num = nums2.size() / 2;
//    int index = 0;
//    while (num--) {
//        ans = ans * nums2[index] * nums2[index + 1];
//        index += 2;
//    }
//
//    if (nums1.size() == 0 && nums2.size() == 1) {
//        if (ret) return 0;
//        else return nums2[0];
//    }
//    else if (nums1.size() == 0 && nums2.size() == 0) return 0;
//    else return ans;
//}

//一次遍历方法，时间复杂度为O(N)
long long maxStrength(vector<int>& nums) {
    long long mn = nums[0], mx = mn;
    for (int i = 1; i < nums.size(); i++) {
        long long x = nums[i];
        long long tmp = mn;
        mn = min({ mn, x, mn * x, mx * x });
        mx = max({ mx, x, tmp * x, mx * x });
    }
    return mx;
}

int main() {

	return 0;
}