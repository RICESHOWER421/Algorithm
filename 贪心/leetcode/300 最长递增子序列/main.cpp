#include <iostream>
#include <vector>
using namespace std;

//不同于之前的动态规划，这里使用的是贪心 + 二分
//但是这个思路一开始我很疑惑，现在摸清楚后赶快记录一下
//首先就是这个策略是不是正确的，然后我就想到了一个例子
//假如这个案例给的是1 2 3 5 10 4
//那么我们可以由该案例知道，我们所得到的最长递增子序列应该是1 2 3 5 10
//但是，这里ret值存的却是1 2 3 4 10，明显不是最长递增子序列。
//回答是，这道题目要求返回的是最长递增子序列的长度，注意是长度，如果让你返回该序列的话就不行了。
//这里ret存储的不应该理解为存储的是最长递增子序列，而是理想的最长递增子序列
//比如说，虽然案例1 2 3 5 10 4中，ret为1 2 3 4 10不是最长递增子序列，但是假如后面还有数字呢？
//比如1 2 3 5 10 4 6 7 8 9，这个案例我们就不难看出二分+贪心的策略了，这个案例的ret为1 2 3 4 6 7 8 9就是最长递增子序列
//所以说，这两个案例就能总结出贪心+二分的策略：我们遍历数组nums，如果出现nums[i]的元素比ret最末尾的元素大，那我们就将它加到ret末尾去，如果比他小，我们就将其放入ret对应大小的下标位置。如果该数后面有更长的递增序列，那么ret也会同步更新；如果没有，也不影响最长递增子序列的大小
int lengthOfLIS(vector<int>& nums) {
    vector<int> ret;
    ret.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > ret.back()) ret.push_back(nums[i]);
        else {
            int left = 0, right = ret.size() - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (ret[mid] >= nums[i]) right = mid;
                else left = mid + 1;
            }
            ret[left] = nums[i];
        }
    }
    return ret.size();
}
int main() {

	return 0;
}