#include <iostream>
#include <vector>
using namespace std;

int gcd(int x, int y) {
    while (x % y) {
        int c = x % y;
        x = y;
        y = c;
    }
    return y;
}

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            for (int j = i + 1; j < (int)nums.size(); j++) {
                int a = nums[i], b = nums[j] % 10;
                while (a / 10) {
                    a /= 10;
                }

                ans += (gcd(a, b) == 1 ? 1 : 0);
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}