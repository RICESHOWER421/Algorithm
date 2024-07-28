#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

//未用红黑树版本，时间复杂度O(N^2)超时
int longestSubarray(vector<int>& nums, int limit) {
    int left = 0, right = 0;
    int max_len = 1;
    int max_num = INT_MIN, min_num = INT_MAX;
    while (left < nums.size()) {
        max_num = max(max_num, nums[right]);
        min_num = min(min_num, nums[right]);
        if (abs(max_num - min_num) <= limit) {
            max_len = max(max_len, right - left + 1);
            ++right;
        }
        if (right == nums.size() || abs(max_num - min_num) > limit) {
            ++left;
            right = left;
            max_num = INT_MIN;
            min_num = INT_MAX;
        }
    }
    return max_len;
}

//红黑树优化版本
int longestSubarray(vector<int>& nums, int limit) {
    multiset<int> s;
    int n = nums.size();
    int left = 0, right = 0;
    int ret = 0;
    while (right < n) {
        s.insert(nums[right]);
        while (*s.rbegin() - *s.begin() > limit) {
            s.erase(s.find(nums[left++]));
        }
        ret = max(ret, right - left + 1);
        right++;
    }
    return ret;
}

int main() {
	vector<int> nums = { 10,1,2,4,7,2 };
	int limit = 5;
	cout << longestSubarray(nums, limit) << endl;
	return 0;
}