#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for (auto& x : weights) {
            left = max(x, left);
            right += x;
        }

        while (left < right) {
            int mid = (left + right) / 2;

            int day = 1, sum = 0;
            for (auto& x : weights) {
                if (sum + x > mid) {
                    ++day;
                    sum = 0;
                }
                sum += x;
            }

            if (day <= days) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {

	return 0;
}
