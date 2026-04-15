#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> hash_map;
        vector<int> arr(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            auto& x = hash_map[nums[i]];
            x.push_back(i);
            int len = x.size();
            if (len >= 2) {
                arr[x.back()] = min(arr[x.back()], min(x.back() - x[len - 2], n - x.back() + x[0]));
                arr[x[len - 2]] = min(arr[x[len - 2]], x.back() - x[len - 2]);
                arr[x[0]] = min(arr[x[0]], n - x.back() + x[0]);
            }
        }
        vector<int> ans;
        for (auto& x : queries) {
            ans.push_back(arr[x] == INT_MAX ? -1 : arr[x]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = { 1,3,1,4,1,3,2 }, queries = {0,3,5};
    vector<int> ans = Solution().solveQueries(nums, queries);
    for (auto& x : ans){
        cout << x << " ";
    }
    cout << "\n";
	return 0;
}