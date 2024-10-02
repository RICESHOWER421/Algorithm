#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int Binary_Search(vector<int>& arr, int find) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] < find) left = mid + 1;
            else right = mid;
        }
        return (left == arr.size() || arr[left] != find ? left - 1 : left);
    }

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> ans;

        sort(nums.begin(), nums.end());
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }

        for (int i = 0; i < (int)queries.size(); i++) {
            ans.push_back(Binary_Search(dp, queries[i]));
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {4,5,2,1};
    vector<int> queries = { 3,10,21 };
    vector<int> ans = Solution().answerQueries(nums, queries);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
	return 0;
}