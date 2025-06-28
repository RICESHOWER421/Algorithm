#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> tmp(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            tmp[i] = { nums[i], i };
        }
        sort(tmp.begin(), tmp.end(), greater<pair<int, int>>());
        sort(tmp.begin(), tmp.begin() + k, [&](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
            });
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(tmp[i].first);
        }
        return ans;
    }
};

int main() {

	return 0;
}