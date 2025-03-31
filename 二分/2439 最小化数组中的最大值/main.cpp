#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size(), l = nums[0], r = -1;
        for (int i = 1; i <= n; i++) {
            r = max(r, nums[i - 1]);
        }

        while (l < r) {
            int mid = l + (r - l) / 2, ret = 0;
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (nums[i] < mid) {     //到不了的数向后面借值
                    ret -= (mid - nums[i]);
                }
                else {      //超过的数向前面给值
                    ret += (nums[i] - mid);
                }
                if (ret > 0) {    //如果此时ret值为正数，说明此时绝对存在值超过mid值的情况
                    ok = false;
                    break;
                }
            }
            if (ok) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return r;
    }
};

int main() {
    vector<int> nums = { 2,7,9,19,5,19 };
    cout << Solution().minimizeArrayValue(nums) << "\n";
	return 0;
}