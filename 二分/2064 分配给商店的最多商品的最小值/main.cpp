#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = 0;
        for (auto& x : quantities) {
            right += x;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
          
            for (auto& x : quantities) {
                count += (x / mid) + (x % mid != 0);
            }

            if (count >= n) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {
    vector<int> nums = { 312,123,12,3123,12,4,32,43,65,34,5,234,234 };
    int n = 14;
    cout << Solution().minimizedMaximum(n, nums) << "\n";
	return 0;
}