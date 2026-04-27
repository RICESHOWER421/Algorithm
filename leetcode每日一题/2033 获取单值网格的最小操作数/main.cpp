#include <bits/stdc++.h>
using namespace std;

/*
排序 + 前缀和
看题解说是中位数贪心就是正确答案，我没证出来，所以我直接用的O(N)前缀和枚举答案
枚举公式：
假设给出排好序的数组，要求把所有数字变成元素j，比j小的数设为i，它出现了cnt1次，比j大的数设为k，他出现了cnt2次，那么这两个数要变到j所需要的步数为：
(j - i) / x * cnt1 + (k - j) / x * cnt2
化简可得：
(j * cnt1 - i * cnt1 + k * cnt2 - j * cnt2) / x
所以，我们可以将数组分为两部分：j左边部分和j右边部分，然后分别维护两个部分的两个变量值：各部分的数的个数之和 各部分每个元素与它的个数的乘积之和 就可以算出答案
*/
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int, int> hash_map;
        vector<int> nums;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (hash_map.find(grid[i][j]) == hash_map.end()) {
                    nums.push_back(grid[i][j]);
                }
                hash_map[grid[i][j]]++;
            }
        }
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] - nums[i - 1]) % x) return -1;
        }

        int ans = INT_MAX, l1 = 0, l2 = 0, r1 = 0, r2 = 0;
        for (int i = 1; i < nums.size(); i++) {
            r1 += nums[i] * hash_map[nums[i]];
            r2 += hash_map[nums[i]];
        }

        for (int i = 0; i < nums.size(); i++) {
            ans = min(ans, (nums[i] * l2 - l1 + r1 - nums[i] * r2) / x);
            l1 += nums[i] * hash_map[nums[i]];
            if (i + 1 < nums.size()) r1 -= nums[i + 1] * hash_map[nums[i + 1]];
            l2 += hash_map[nums[i]];
            if (i + 1 < nums.size()) r2 -= hash_map[nums[i + 1]];
        }
        return ans;
    }
};

int main() {

	return 0;
}