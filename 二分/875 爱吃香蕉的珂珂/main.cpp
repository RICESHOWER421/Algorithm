#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 0;
        for (auto& x : piles) {
            right = max(x, right);
        }

        while (left < right) {
            int mid = (left + right) / 2;
            int times = 0;
            for (auto& x : piles) {
                times += x / mid + (x % mid != 0);
            }

            if (times > h) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

int main() {

	return 0;
}