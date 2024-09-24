#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
	long long maximumSubsequenceCount(string text, string pattern) {
		long long ans = 0;
		long long first = 0, second = 0;
		for (int i = 0; i < (int)text.size(); i++) {
			if (pattern[0] == pattern[1]) {
				if (text[i] == pattern[0]) {
					if (first) ans += first;
					++first;
				}
			}
			else {
				if (text[i] == pattern[0]) ++first;
				else if (text[i] == pattern[1]) {
					ans += first;
					++second;
				}
			}
		}
		return ans + max(first, second);
	}
};

int main() {

	return 0;
}