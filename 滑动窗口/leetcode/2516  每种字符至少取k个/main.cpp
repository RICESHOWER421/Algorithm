#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int takeCharacters(string s, int k) {
	vector<int> nums(3);
	for (int i = 0; i < s.size(); i++) nums[s[i] - 'a']++;

	for (int i = 0; i < 3; i++) {
		nums[i] -= k;
		if (nums[i] < 0) return -1;
	}

	int left = 0;
	int ret = 0;
	for (int i = 0; i < s.size(); i++) {
		nums[s[i] - 'a']--;
		if (nums[s[i] - 'a'] < 0) {
			while (nums[s[i] - 'a'] < 0) {
				nums[s[left] - 'a']++;
				++left;
			}
		}
		ret = max(ret, i - left + 1);
	}

	return s.size() - ret;
}

int main() {
	string s = "aabcabcabbcabbcabbcaabbcaabbbccccaa";
	int k = 6;
	cout << takeCharacters(s, k) << endl;
	return 0;
}