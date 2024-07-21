#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxVowels(string s, int k) {
	vector<int> dp(s.size() + 1);
	for (int i = 1; i <= s.size(); i++) {
		if (s[i - 1] == 'a' || s[i - 1] == 'e' || s[i - 1] == 'i' || s[i - 1] == 'o' || s[i - 1] == 'u') dp[i] = dp[i - 1] + 1;
		else dp[i] = dp[i - 1];
	}

	int max_num = INT_MIN;
	for (int i = k; i <= s.size(); i++)
		max_num = max(max_num, dp[i] - dp[i - k]);
	return max_num;
}
int main() {

	return 0;
}