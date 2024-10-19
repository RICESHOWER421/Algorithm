#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] + ret) % 2 == 0) {
                ++ans;
                ++ret;
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}