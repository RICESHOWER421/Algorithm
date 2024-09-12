#include <iostream>
#include <vector>
using namespace std;

bool checkArray(vector<int>& nums, int k) {
	int n = nums.size();
	vector<int> diff(n), judge(n + 1);

	diff[0] = nums[0];
	for (int i = 1; i < n; i++) {
		diff[i] = nums[i] - nums[i - 1];
	}
	
	for (int i = 0; i < n; i++) {
		if (i < k) {
			if (diff[i] < 0) return false;		//如果在i < k时出现diff[i] < 0，说明此时一定有数字是消不掉的
			if (i + k < n + 1) {
				judge[i] += diff[i];
				judge[i + k] -= diff[i];
			}
			else {
				if (diff[i]) return false;
			}
		}
		else {
			if (diff[i] > judge[i]) {
				if (i + k < n + 1) {
					judge[i + k] -= (diff[i] - judge[i]);
				}
				else return false;
			}
			else if (diff[i] == judge[i]) continue;
			else return false;
		}
	}
	return true;
}

int main() {
	vector<int> nums = {5,1,3,7};
	cout << checkArray(nums, 2) << endl;
	return 0;
}