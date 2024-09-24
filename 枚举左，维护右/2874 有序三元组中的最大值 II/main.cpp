#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//枚举k方法
class Solution {
public:
	long long maximumTripletValue(vector<int>& nums) {
		long long ans = 0;
		int mx = 0, premx = 0;
		for (auto& x : nums) {
			ans = max(ans, (long long)mx * x);
			mx = max(mx, premx - x);
			premx = max(premx, x);
		}
		return ans;

	}
};

//枚举j方法
class Solution {
public:
	long long maximumTripletValue(vector<int>& nums) {
		int n = (int)nums.size();
		vector<int> arr(n + 1);
		for (int i = n - 1; i > 1; i--) {
			arr[i] = max(arr[i + 1], nums[i]);
		}

		long long ans = 0;
		int prev_mx = nums[0];
		for (int i = 1; i < n - 1; i++) {
			ans = max(ans, (long long)(prev_mx - nums[i]) * arr[i + 1]);
			prev_mx = max(prev_mx, nums[i]);
		}
		return ans;
	}
};

int main(){

	return 0;
}