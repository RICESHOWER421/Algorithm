#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 0, right = 300000000;
        while (left < right) {
            long long mid = (left + right) / 2;
            if (mid * (1 + mid) / 2 < n) left = mid + 1;
            else right = mid;
        }
        return left * (1 + left) / 2 == n ? left : left - 1;
    }
};

int main() {
    int n = 7;
    cout << Solution().arrangeCoins(n) << endl;
	return 0;
}