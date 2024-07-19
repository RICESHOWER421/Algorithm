#include <iostream>
#include <vector>
using namespace std;

void duplicateZeros(vector<int>& arr) {
	int left = 0, right = -1;
	while (right < (int)arr.size() - 1) {
		if (arr[left++])
			++right;
		else
			right += 2;
	}
	--left;

	if (right == arr.size()) {
		arr[right - 1] = 0;
		right -= 2;
		--left;
	}

	while (left >= 0 && right >= 0) {
		if (arr[left]) {
			arr[right--] = arr[left];
		}	
		else {
			arr[right] = arr[right - 1] = 0;
			right -= 2;
		}
		--left;
	}
}

int main() {
	vector<int>nums = { 1,0,2,3,0,4,5,0 };
	duplicateZeros(nums);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}