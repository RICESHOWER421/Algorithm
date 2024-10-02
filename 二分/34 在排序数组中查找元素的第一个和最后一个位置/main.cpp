#include <iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
	//特殊情况：如果nums为0，则直接返回{-1, -1}
	if (nums.size() == 0) return { -1, -1 };
	int begin = 0, end = 0;
	int left = 0, right = nums.size() - 1;
	//寻找target第一次出现的下标
	while (left < right) { //不能相等，否则会进入死循环
		int mid = left + (right - left) / 2; //不能使用left + (right - left + 1) / 2，否则会进入死循环
		if (nums[mid] < target) left = mid + 1;
		else right = mid;
	}
	//判断此时left和right指向的是不是target值
	if (nums[left] == target) begin = left;
	else return { -1, -1 };

	//寻找target最后一次出现的下标
	right = nums.size() - 1; //left不需要重置为0，因为此时left就是target第一次出现的下标
	while (left < right) { //不能相等原理相同
		int mid = left + (right - left + 1) / 2;   //不能使用left + (right - left) / 2原理和上面相同
		if (nums[mid] > target) right = mid - 1;
		else left = mid;
	}
	//判断此时right下标指向的值是不是target值
	if (nums[right] == target) {
		end = right;
		return { begin, end };
	}
	else return { -1, -1 };
}

int main() {
	vector<int> nums = { 5 };
	vector<int> return_nums = searchRange(nums, 5);
	cout << return_nums[0] << " " << return_nums[1] << endl;
	return 0;
}