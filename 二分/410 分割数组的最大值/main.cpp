#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = -1, right = 0;
        for (auto& x : nums) {
            left = max(left, x);
            right += x;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            bool ok = true;
            int count = 0, sum = 0;
            for (auto& x : nums) {
                if (sum + x <= mid) {
                    sum += x;
                }
                else {
                    ++count;
                    if (count == k) {
                        ok = false;
                        break;
                    }
                    sum = x;
                }
            }

            if (ok) right = mid;
            else left = mid + 1;
        }
        return right;
    }
};

int main() {
    vector<int> nums = { 312,12,312,3,123,124,234,3244,523,5,214213 };
    int k = 10;
    cout << Solution().splitArray(nums, k) << "\n";
    return 0;
}