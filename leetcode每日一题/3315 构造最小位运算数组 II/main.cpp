#include <bits/stdc++.h>
using namespace std;

//做法和3314一样
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 2) {
                ans.push_back(-1);
                continue;
            }

            int tmp = nums[i], cnt = 0;
            while (tmp && (tmp & 1)) {
                tmp >>= 1;
                ++cnt;
            }
            ans.push_back(nums[i] - pow(2, cnt - 1));
        }
        return ans;
    }
};

int main() {

    return 0;
}