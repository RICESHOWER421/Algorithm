#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maximumSum(vector<int>& arr) {
    int n = arr.size();
    //dp[i][j]��ʾ��iΪ��β���������У�ɾ����k�ε�����������
    vector<vector<int>> dp(n + 1, vector<int>(2));

    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], 0) + arr[i - 1];  //Ҫô��ǰ��û��ɾ����Ҫô��ǰ��һ����ѡ
        if (i == 1) dp[i][1] = dp[i - 1][1] + arr[i - 1];   //������ǵ�һ���Ļ������������鲻��Ϊ�գ�����ֻ���ڵڶ������
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