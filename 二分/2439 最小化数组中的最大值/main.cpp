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
                if (nums[i] < mid) {     //�����˵���������ֵ
                    ret -= (mid - nums[i]);
                }
                else {      //����������ǰ���ֵ
                    ret += (nums[i] - mid);
                }
                if (ret > 0) {    //�����ʱretֵΪ������˵����ʱ���Դ���ֵ����midֵ�����
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