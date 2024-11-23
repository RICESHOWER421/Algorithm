#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    using ll = long long;
    long long repairCars(vector<int>& ranks, int cars) {
        ll left = 1, right = 0;
        for (auto& x : ranks) {
            right = max((ll)x * cars * cars, right);
        }

        while (left < right) {
            ll mid = (left + right) / 2;

            ll sum = 0;
            for (auto& x : ranks) {
                ll tmp = floor(sqrt(mid / (double)x));
                sum += tmp;
            }

            if (sum >= cars) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {

	return 0;
}