#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                ret.push_back(i);
            }
        }

        vector<int> ans;
        for (auto& x : queries) {
            if (x > ret.size()) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(ret[x - 1]);
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}