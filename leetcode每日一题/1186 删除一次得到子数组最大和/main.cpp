#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maximumSum(vector<int>& arr) {
    int n = arr.size();
    //dp[i][j]表示以i为结尾的子数组中，删除了k次的最大子数组和
    vector<vector<int>> dp(n + 1, vector<int>(2));

    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], 0) + arr[i - 1];  //要么你前面没有删除，要么你前面一个不选
        if (i == 1) dp[i][1] = dp[i - 1][1] + arr[i - 1];   //如果你是第一个的话，由于子数组不能为空，所以只存在第二种情况
        else dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i - 1]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    return ans;
}

int main() {
	vector<int> arr = {-1,2,3,4,5,6,7,8,-2};
	cout << maximumSum(arr) << endl;
	return 0;
}