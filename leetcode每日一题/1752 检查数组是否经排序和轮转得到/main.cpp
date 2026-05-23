#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                if (ok && nums[i] <= nums[0]) ok = false;
                else return false;
            }
            else {
                if (!ok && nums[i] > nums[0]) return false;
            }
        }
        return true;
    }
};

int main() {

	return 0;
}