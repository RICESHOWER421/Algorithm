#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ret = 0;
        for (auto& x : nums) {
            if (x < k) {
                ++ret;
            }
        }
        return ret;
    }
};

int main() {

	return 0;
}