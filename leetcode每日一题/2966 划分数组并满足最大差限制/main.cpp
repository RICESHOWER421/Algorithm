#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> path;
        for (int i = 0; i < nums.size(); i++) {
            if (path.empty()) path.push_back(nums[i]);
            else {
                if (nums[i] - path[0] > k) return {};
                else path.push_back(nums[i]);
                if (path.size() == 3) {
                    ans.push_back(path);
                    path.clear();
                }
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}