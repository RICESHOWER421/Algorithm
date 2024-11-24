#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    using ll = long long;
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 0, right = 0;
        for (auto& x : candies) {
            right = max(right, x);
        }

        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            ll sum = 0;
            for (auto& x : candies) {
                sum += x / mid;
            }
            if (sum >= k) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};

int main() {

	return 0;
}