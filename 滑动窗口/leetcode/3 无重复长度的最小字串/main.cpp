#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int lengthOfLongestSubstring(string s) {
	int n = s.size();
	int left = 0, right = 0, max_len = INT_MIN;
	vector<int> nums(200);
	while (right <= n - 1) {
		if (nums[s[right]] == 0) {
			++nums[s[right]];
			++right;
			max_len = max(max_len, right - left);
		}
		else {
			nums[s[left++]] = 0;
		}
	}
	return max_len;
}

int main() {
	string s = "";
	cout << lengthOfLongestSubstring(s) << endl;
	return 0;
}