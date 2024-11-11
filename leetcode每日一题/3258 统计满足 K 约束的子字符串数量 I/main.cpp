#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int countKConstraintSubstrings(string s, int k) {
		int left = 0, right = 0;
		int count = 0, ans = 0, ret1 = 0, ret2 = 0;
		while (right < s.size()) {
			if (s[right] == '0') ++ret1;
			else ++ret2;

			while (ret1 > k && ret2 > k) {
				if (s[left] == '0') --ret1;
				else --ret2;
				--count;
				++left;
			}

			++count;
			ans += count;
			++right;
		}
		return ans;
	}
};

int main() {
	string s = "10101";
	cout << Solution().countKConstraintSubstrings(s, 1) << "\n";
	return 0;
}