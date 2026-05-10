#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> cnts(n, -1);
        cnts[0] = 0;
        for (int i = 0; i < n; i++) {
            //cnts[i] == -1表示该点不可达
            if (cnts[i] != -1) {
                for (int j = i + 1; j < n; j++) {
                    if (abs(nums[j] - nums[i]) <= target) {
                        cnts[j] = max(cnts[j], cnts[i] + 1);
                    }
                }
            }
        }
        return cnts[n - 1];
    }
};

int main() {

	return 0;
}