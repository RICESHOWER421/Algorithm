#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        bool ok1 = false, ok2 = false, ok3 = false;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                if (!ok1) ok1 = true;
                else {
                    if (ok2) ok3 = true;
                }
            }
            else if (nums[i] < nums[i - 1]) {
                if (!ok1) return false;
                else {
                    if (ok3) return false;
                    else ok2 = true;
                }
            }
            else return false;
        }
        return ok1 && ok2 && ok3;
    }
};

int main() {

	return 0;
}