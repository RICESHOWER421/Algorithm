#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) return -1;

        int left = 1, right = 0;
        for (auto& x : bloomDay) {
            right = max(right, x);
        }

        while (left < right) {
            int mid = (left + right) / 2;

            int count = 0, ret = 0;
            for (auto& x : bloomDay) {
                if (mid >= x) {
                    ++count;
                    if (count == k) {
                        ++ret;
                        count = 0;
                    }
                }
                else count = 0;
            }

            if (ret >= m) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {
    vector<int> nums = { 1,10,3,10,2 };
    int m = 3, k = 1;
    cout << Solution().minDays(nums, m, k) << "\n";
	return 0;
}