#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 37;
        for (int i = 0; i < (int)nums.size(); i++) {
            int num = nums[i], sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};

int main() {

	return 0;
}