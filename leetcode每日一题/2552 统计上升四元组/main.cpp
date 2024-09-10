#include <iostream>
#include <vector>
using namespace std;

long long countQuadruplets(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> great(n, vector<int>(n + 1));
	for (int k = n - 2; k >= 2; k--) {
		great[k] = great[k + 1];
		for (int x = 1; x < nums[k + 1]; x++) {
			great[k][x]++;
		}
	}

	long long ans = 0;
	vector<int> less(n + 1);
	for (int j = 1; j < n - 2; j++) {
		for (int x = nums[j - 1] + 1; x <= n; x++) {
			less[x]++;
		}

		for (int k = j + 1; k < n - 1; k++) {
			if (nums[j] > nums[k]) {
				ans += (less[nums[k]] * great[k][nums[j]]);
			}
		}
	}
	return ans;
}

int main() {

	return 0;
}