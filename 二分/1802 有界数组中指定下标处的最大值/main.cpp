#include <iostream>
using namespace std;

class Solution {
public:
    using ll = long long;
    int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum;
        while (left < right) {
            ll mid = left + (right - left + 1) / 2;
            ll r = (n - index - 1 >= mid - 1 ? (mid - 1) * mid / 2 + (n - index - 1) - (mid - 1) : (n - index - 1) * (mid - 1 + mid - 1 - (n - index - 2)) / 2), l = index >= mid - 1 ? (mid - 1) * mid / 2 + index - (mid - 1) : index * (mid - 1 + mid - 1 - (index - 1)) / 2;
            if (mid + l + r > maxSum) right = mid - 1;
            else left = mid;
        }
        return left;
    }
};

int main() {
    cout << Solution().maxValue(6, 1, 10) << "\n";
	return 0;
}