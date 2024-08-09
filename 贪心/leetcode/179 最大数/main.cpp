#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const string& s1, const string& s2) {
	return s1 + s2 > s2 + s1;
}

string largestNumber(vector<int>& nums) {
	vector<string> arr;
	for (int i = 0; i < nums.size(); i++)
		arr.push_back(to_string(nums[i]));

	sort(arr.begin(), arr.end(), cmp);
	
	string return_str;
	for (int i = 0; i < arr.size(); i++)
		return_str += arr[i];
	
	//特殊处理，当第一位数字是0的时候
	if (return_str[0] == '0') return "0";
	else return return_str;
}

int main() {
	vector<int> nums = { 3,30,34,5,9 };
	cout << largestNumber(nums) << endl;
	return 0;
}