#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//n * (1 + n) / 2 * nums[i] = time;
//n * n + n - time / nums[i] * 2 = 0;
//¶þ·Ö´ð°¸
class Solution {
public:
    using ll = long long;
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll left = 1, right = 0;
        for (auto& x : workerTimes) {
            right = max(right, (ll)mountainHeight * (1 + (ll)mountainHeight) / 2 * (ll)x);
        }

        while (left < right) {
            ll mid = (left + right) / 2;
            ll sum = 0;
            for (auto& x : workerTimes) {
                ll ret = floor((sqrt(1 + 8 * mid / (ll)x) - 1) / 2.0);
                sum += ret;
            }

            if (sum >= mountainHeight) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {
    int m = 4;
    vector<int> nums = {2,1,1};
    cout << Solution().minNumberOfSeconds(m, nums) << "\n";
    return 0;
}