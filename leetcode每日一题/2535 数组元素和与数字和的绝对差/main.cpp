#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum_1 = 0, sum_2 = 0;
        for (auto& x : nums) {
            sum_1 += x;
            while (x) {
                sum_2 += x % 10;
                x /= 10;
            }
        }
        return abs(sum_1 - sum_2);
    }
};

int main() {

    return 0;
}