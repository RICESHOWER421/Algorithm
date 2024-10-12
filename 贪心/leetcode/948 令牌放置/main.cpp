#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size() - 1;

        int ret = 0;
        int ans = 0;
        while (left <= right) {
            if (tokens[left] <= power) {
                power -= tokens[left++];
                ++ret;
            }
            else {
                ans = max(ret, ans);
                power += tokens[right--];
                if (ret) --ret;
                else break;
            }
        }
        return max(ret, ans);
    }
};

int main() {

	return 0;
}