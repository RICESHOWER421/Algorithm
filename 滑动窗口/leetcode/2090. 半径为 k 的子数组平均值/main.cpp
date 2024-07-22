#include <iostream>
#include <vector>
using namespace std;

vector<int> getAverages(vector<int>& nums, int k) {
	if (nums.size() < 2 * k + 1) {
		vector<int> ret(nums.size(), -1);
		return ret;
	}

	vector<int> ret(nums.size());
	long long sum = 0;
	for (int i = 0; i < 2 * k + 1; i++) sum += nums[i];
	
	for (int i = 0; i < nums.size(); i++) {
		if (i - k < 0 || i + k > nums.size() - 1) ret[i] = -1;
		else {
			if(i != k) sum = sum - nums[i - k - 1] + nums[i + k];
			ret[i] = sum / (2 * k + 1);
		}
	}
	return ret;
}

int main() {

	return 0;
}