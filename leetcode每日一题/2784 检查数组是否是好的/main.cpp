#include <bits/stdc++.h>
using namespace std;

//直接排序
class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i != n - 1 && nums[i] != i + 1) return false;
            else if (i == n - 1 && nums[i] != n - 1) return false;
        }
        return true;
    }
};

//牺牲空间换时间
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnts(n);
        for (auto& x : nums) {
            if (x >= n) return false;
            cnts[x]++;
        }
        for (int i = 1; i <= n - 1; i++) {
            if (i != n - 1 && cnts[i] != 1 || i == n - 1 && cnts[i] != 2) return false;
        }
        return true;
    }
};

int main(){

	return 0;
}