#include <iostream>
#include <vector>
using namespace std;
int peakIndexInMountainArray(vector<int>& arr) {
	int left = 0, right = arr.size() - 1;
	while (left < right) {
		int mid = left + (right - left + 1) / 2;
		if (arr[mid] > arr[mid - 1]) left = mid;
		else right = mid - 1;
	}
	return left;
}

int main() {
	vector<int> nums = {0,1,2,3,4,5,6,7,8,9,0};
	cout << peakIndexInMountainArray(nums) << endl;
	return 0;
}

