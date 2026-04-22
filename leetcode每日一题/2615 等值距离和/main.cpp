#include <bits/stdc++.h>
#include <unordered_map>
typedef long long ll;
using namespace std;

// 这么写必然超时
// class Solution
// {
// public:
//     using ll = long long;
//     vector<long long> distance(vector<int> &nums)
//     {
//         unordered_map<int, vector<int>> idx;
//         int n = nums.size();
//         vector<ll> ans(n);
//         for (int i = 0; i < n; i++)
//         {
//             if (idx.find(nums[i]) != idx.end())
//             {
//                 ll sum = 0;
//                 for (auto &x : idx[nums[i]])
//                 {
//                     int ret = i - x;
//                     ans[x] += ret;
//                     sum += ret;
//                 }
//                 idx[nums[i]].push_back(i);
//                 ans[i] = sum;
//             }
//             else
//                 idx[nums[i]].push_back(i);
//         }
//         return ans;
//     }
// };

//使用前缀和优化，一共两遍，一遍从左往右，一遍从右往左
class Solution {
public:
    using ll = long long;
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> idx;
        unordered_map<int, ll> sum;
        vector<ll> ans(n);
        for (int i = 0; i < n; i++) {
            auto& arr = idx[nums[i]];
            arr.push_back(i);
            if (arr.size() > 1) {
                ll cnt = arr.size(), idx_mul = arr[cnt - 1] - arr[cnt - 2];
                --cnt;
                ans[i] = sum[nums[i]] + cnt * idx_mul;
                sum[nums[i]] += idx_mul * cnt;
            }
        }

        idx.clear();
        sum.clear();

        for (int i = n - 1; i >= 0; i--) {
            auto& arr = idx[nums[i]];
            arr.push_back(i);
            if (arr.size() > 1) {
                ll cnt = arr.size(), idx_mul = arr[cnt - 2] - arr[cnt - 1];
                --cnt;
                ans[i] += sum[nums[i]] + cnt * idx_mul;
                sum[nums[i]] += idx_mul * cnt;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums;
     for (int i = 1; i <= 1e5; i++){
         nums.push_back(1);
     }
    vector<ll> ans = Solution().distance(nums);
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
