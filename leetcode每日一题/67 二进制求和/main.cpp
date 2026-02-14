#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string return_str;
		int left = a.size() - 1, right = b.size() - 1;
		int ret = 0;
		while (left >= 0 || right >= 0) {
			int left_num = 0, right_num = 0;
			if (left >= 0) {
				left_num = a[left] - '0';
				--left;
			}
			if (right >= 0) {
				right_num = b[right] - '0';
				--right;
			}

			int add = (left_num + right_num + ret) % 2;
			ret = (left_num + right_num + ret) / 2;
			return_str += (add + '0');
		}

		if (ret == 1) {
			return_str += '1';
		}

		reverse(return_str.begin(), return_str.end());
		return return_str;
	}
};

int main() {

	return 0;
}