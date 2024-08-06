#include <iostream>
#include <string>
#include <vector>
using namespace std;

string optimalDivision(vector<int>& nums) {
	if (nums.size() == 1) return to_string(nums[0]);
	else if (nums.size() == 2) return to_string(nums[0]) + '/' + to_string(nums[1]);
	string ret;
	ret += to_string(nums[0]) + '/' + '(';
	for (int i = 1; i < nums.size(); i++) {
		ret += to_string(nums[i]);
		if (i != nums.size() - 1) ret += '/';
	}
	ret += ')';
	return ret;
}

int main() {
	vector<int> nums = { 1000,100,10,2 };
	cout << optimalDivision(nums) << endl;
	return 0;
}