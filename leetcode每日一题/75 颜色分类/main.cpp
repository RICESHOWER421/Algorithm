#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int left = 0, right = nums.size() - 1, cur = 0;
		while (cur <= right) {
			if (nums[cur] == 0) {
				swap(nums[left++], nums[cur]);
				if (cur <= left) ++cur;
			}
			else if (nums[cur] == 2) swap(nums[right--], nums[cur]);
			else ++cur;
		}
	}
};

int main() {

	return 0;
}