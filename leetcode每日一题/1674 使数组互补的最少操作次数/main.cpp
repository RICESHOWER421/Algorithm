#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        //设diff[k]表示nums[i] + nums[n - i - 1] == k所需要的次数
        vector<int> diff(limit * 2 + 2);

        for (int i = 0; i < n / 2; i++) {
            int l_num = nums[i], r_num = nums[n - 1 - i];
            int l = min(l_num, r_num) + 1, r = max(l_num, r_num) + limit;

            //对于[2, l - 1]部分，两个值都需要改变
            diff[2] += 2;
            diff[l] -= 2;

            //对于[l,r]部分，只需要改一个值即可
            diff[l]++;
            diff[r + 1]--;

            //然后在[l,r]中存在l_num + r_num，由于此时不需要变值不变，但[l,r]区间都 + 1，所以需要减去
            diff[l_num + r_num]--;
            diff[l_num + r_num + 1]++;

            //最后是[r + 1, 2 * limit]，两个值都需要改变
            diff[r + 1] += 2;
            diff[2 * limit + 1] -= 2;
        }

        int ans = 2 * n, sum = 0;
        for (int i = 2; i <= 2 * limit; i++) {
            sum += diff[i];
            ans = min(ans, sum);
        }
        return ans;
    }
};

int main() {

	return 0;
}