#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        auto dfs = [&](this auto&& dfs, int x)->void {
            if (x == 0) return;
            int ret = x % 10;
            dfs(x / 10);
            ans.push_back(ret);
        };
        for (auto& x : nums) {
            int num = x;
            dfs(num);
        }
        return ans;
    }
};

int main() {

	return 0;
}