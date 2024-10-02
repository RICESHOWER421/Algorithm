#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	int return_num = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (nums[mid] == target) {
			return_num = mid;
			break;
		}
		else if (nums[mid] > target) right = mid - 1;
		else left = mid + 1;
	}
	return return_num;
}

int main() {
	
	return 0;
}