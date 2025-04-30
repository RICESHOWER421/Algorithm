#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (auto& x : nums) {
            int tmp = x, cnt = 0;
            while (tmp) {
                ++cnt;
                tmp /= 10;
            }
            ans += (cnt % 2 == 0);
        }
        return ans;
    }
};

int main() {

	return 0;
}