#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

//一开始我想的贪心策略是：将所有数分为3类，一类模三余0，一类数模三余一，一类模三余二，然后对数组进行升序排序，然后对数组从后往前进行遍历，如果这个数属于第一类，那么这个数一定可以加上，如果是第二类或第三类，那么就需要进行匹配最后求得最大值，但这种贪心是错误的，最后卡在了第四十个案例，与答案差了3，感觉是匹配求最大值出现了问题，而且一时半会我也没想到好的办法，于是有了最优的贪心。
//最优的贪心是：我们先求出所有数的和，如果这个数能被3整除，那么直接返回该结果就行，如果被3除后有余数，那么就是以下两种情况：
//1、余数为1，此时要么是多了一个数，这个数模3余1，减去这个数总和就能被三整除了，此时最优的策略就是减去最小的能够模3余1的数；要么是多了两个数，这两个数都是模3余2的，减去这两个数同样也能被3整除，那么此时最优的策略就是减去最小的和次小的能够模3余2的数。至此我们取两种情况的最优解即可
//2、余数为2，和上面同理，要么多了一个模3余2的数，要么多了两个模3余1的数，最优策略同样和上一种情况一样，最后取两种情况最优解即可。
//所以我们只需要一次循环遍历，分别求出数组所有元素的和以及模3余1和模3余2的最小值和次小值，这道题目也就完成了
int maxSumDivThree(vector<int>& nums) {
	int ans = 0;
	int min_num_1_1 = INT_MAX, min_num_1_2 = INT_MAX;
	int min_num_2_1 = INT_MAX, min_num_2_2 = INT_MAX;
	for (int i = 0; i < nums.size(); i++) {
		ans += nums[i];
        if (nums[i] % 3 == 1) {
            if (nums[i] < min_num_1_2) {
                if (nums[i] < min_num_1_1) {
                    min_num_1_2 = min_num_1_1;
                    min_num_1_1 = nums[i];
                }
                else min_num_1_2 = nums[i];
            }
        }
        if (nums[i] % 3 == 2) {
            if (nums[i] < min_num_2_2) {
                if (nums[i] < min_num_2_1) {
                    min_num_2_2 = min_num_2_1;
                    min_num_2_1 = nums[i];
                }
                else min_num_2_2 = nums[i];
            }
        }
	}
	if (ans % 3 == 0) return ans;
    else {
        if (ans % 3 == 1) {
            int num1 = ans - min_num_1_1;
            int num2 = min_num_2_2 == INT_MAX ? 0 : ans - min_num_2_1 - min_num_2_2;
            return max(num1, num2);
        }
        else {
            int num1 = ans - min_num_2_1;
            int num2 = min_num_1_2 == INT_MAX ? 0 : ans - min_num_1_1 - min_num_1_2;
            return max(num1, num2);
        }
    }
}

int main() {
	vector<int> nums = {1,2,2,2,2,2};
	cout << maxSumDivThree(nums) << endl;
	return 0;
}