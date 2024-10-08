#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	int Binary_Search(vector<int>& nums, int find) {
		int left = 0, right = nums.size();
		while (left < right) {
			int mid = (left + right) / 2;
			if (nums[mid] < find) left = mid + 1;
			else right = mid;
		}

		if (left == (int)nums.size()) return -1;		//²»´æÔÚ´ð°¸
		else return left;
	}

	vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
		vector<int> ans;

		int n = increase.size();
		vector<vector<int>> dp(3, vector<int>(n + 1));
		for (int i = 1; i <= n; i++) {
			dp[0][i] = dp[0][i - 1] + increase[i - 1][0];
			dp[1][i] = dp[1][i - 1] + increase[i - 1][1];
			dp[2][i] = dp[2][i - 1] + increase[i - 1][2];
		}

		for (int i = 0; i < (int)requirements.size(); i++) {
			int index_1 = Binary_Search(dp[0], requirements[i][0]);
			int index_2 = Binary_Search(dp[1], requirements[i][1]);
			int index_3 = Binary_Search(dp[2], requirements[i][2]);

			if (index_1 == -1 || index_2 == -1 || index_3 == -1) ans.push_back(-1);
			else ans.push_back(max({ index_1, index_2, index_3 }));
		}
		return ans;
	}
};

int main() {
	vector<vector<int>> increase = { {2,8,4},{2,5,0},{10,9,8} };
	vector<vector<int>> requirments = { {2,11,3},{15,10,7},{9,17,12},{8,1,14} };
	vector<int> ans = Solution().getTriggerTime(increase, requirments);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}