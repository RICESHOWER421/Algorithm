#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//1 2 3 4
class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int ret = nums[i] - nums[0];
            if (ret == 0 || ret % 2) continue;
            int k = ret / 2;
            vector<bool> vis(n);
            vis[i] = true;
            vector<int> ans;
            ans.push_back((nums[0] + nums[i]) / 2);
            int left = 1, right = i + 1;
            while (right < n) {
                while (left < n && vis[left]) ++left;
                while (right < n && nums[right] - nums[left] < 2 * k) ++right;
                if (right == n || nums[right] - nums[left] > 2 * k) break;
                vis[left] = vis[right] = true;
                ans.push_back((nums[left] + nums[right]) / 2);
                ++left;
                ++right;
            }
            if (ans.size() == n / 2) return ans;
        }
        return {};
    }
};

int main() {

	return 0;
}