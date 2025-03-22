#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> n1(n + 1), n2(n + 1);
        //下标从1开始计算
        //n1表示前i个字符的异或前缀和，n2表示i到后面所有数字的异或前缀和
        for (int i = 1; i <= n; i++) {
            n1[i] = n1[i - 1] | nums[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            n2[i] = n2[i + 1] | nums[i];
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, n1[i] | n2[i + 1] | ((ll)nums[i] << k));
        }
        return ans;
    }
};

//1 2 3
//0 1 2 3
//0 1 3 6
//6 5 3 0

int main() {

	return 0;
}