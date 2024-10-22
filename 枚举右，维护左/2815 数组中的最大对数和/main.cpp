#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> arr(10);
        int ans = -1;
        for (int i = 0; i < (int)nums.size(); i++) {
            int ret = nums[i];
            int mx = -1;
            while (ret) {
                mx = max(mx, ret % 10);
                ret /= 10;
            }
            if (i && arr[mx]) ans = max(ans, arr[mx] + nums[i]);
            arr[mx] = max(arr[mx], nums[i]);
        }
        return ans;
    }
};

int main() {

	return 0;
}