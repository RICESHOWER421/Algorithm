#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int left = 0, right = 0;
		int ret = 0;
		while (right < (int)nums.size()) {
			if (right == 0 || nums[right - 1] == nums[right]) ++ret;
			else ret = 1;

			if (ret <= 2) {
				nums[left] = nums[right];
				++left;
			}
			++right;
		}
		return left;
	}
};

int main() {

	return 0;
}