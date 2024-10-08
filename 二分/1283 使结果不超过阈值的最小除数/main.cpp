#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int max_num = -1;
        for (auto& x : nums) {
            max_num = max(x, max_num);
        }

        int left = 1, right = max_num;
        while (left < right) {
            int mid = (left + right) / 2;
            int sum = 0;
            for (auto& x : nums) {
                sum += (x / mid + (x % mid != 0));
            }

            if (sum <= threshold) right = mid;   //如果我们得到的值比要求的值要小，说明除数要更小才能将值变大
            else left = mid + 1;
        }
        return left;
    }
};

int main() {
    vector<int> nums = {2,3,5,7,11};
    int x = 11;
    cout << Solution().smallestDivisor(nums,x) << endl;
	return 0;
}