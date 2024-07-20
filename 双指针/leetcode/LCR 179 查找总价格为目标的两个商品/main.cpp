#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int>& price, int target) {
	vector<int> return_arr(2);
	int n = price.size();
	int left = 0, right = n - 1;
	while (left < right) {
		if (price[left] + price[right] == target) {
			return_arr[0] = price[left];
			return_arr[1] = price[right];
			break;
		}
		else{
			if (price[left] + price[right] > target) --right;
			else ++left;
	    }
	}
	return return_arr;
}

int main() {
	vector<int> nums = { 8, 21, 27, 34, 52, 66 };
	vector<int> return_arr(2);
	return_arr = twoSum(nums, 118);
	cout << return_arr[0] << " " << return_arr[1] << endl;
	return 0;
}