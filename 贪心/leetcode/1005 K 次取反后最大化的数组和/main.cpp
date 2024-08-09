#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//贪心+分类讨论，细节非常多，不仔细写的话很容易写错，这题wa了两次，一次手贱，一个细节处理
//int largestSumAfterKNegations(vector<int>& nums, int k) {
//	sort(nums.begin(), nums.end());
//	int index = 0;	//记录是否存在0
//	int max_num = INT_MIN; //记录所有负数的最大值
//	int min_num = INT_MAX; //记录所有正数的最小值
//	int ans = 0;		//返回值
//	int temp = 0;		//记录负数的个数
//	for (int i = 0; i < nums.size(); i++) {
//		if (nums[i] == 0) index = 1;
//		else if (nums[i] < 0) {
//			++temp;
//			max_num = max(max_num, nums[i]);
//		}
//		else min_num = min(min_num, nums[i]);
//	}
//
//	if (temp > 0) {		//如果存在负数
//		if (temp > k) {	//负数个数比k的次数还多
//			for (int i = 0; i < nums.size(); i++) {
//				if (i < k) ans += abs(nums[i]);
//				else ans += nums[i];
//			}
//		}
//		else {	//负数个数比k次数要少
//			if (temp % 2 == k % 2) {		//如果负数个数正好和k的大小同奇偶性
//				for (int i = 0; i < nums.size(); i++) {
//					ans += abs(nums[i]);
//				}
//			}
//			else {	//不同奇偶性
//				if (index) {	//如果存在0，那么就可以全部转换为正数
//					for (int i = 0; i < nums.size(); i++) {
//						ans += abs(nums[i]);
//					}
//				}
//				else {			//不存在0的话
//					if (abs(max_num) > min_num) {	//如果负数的最大值的绝对值比正数的最小值还要大，则所有负数变为正数，最小的正数变为负数
//						for (int i = 0; i < nums.size(); i++) {
//							if (nums[i] != min_num) ans += abs(nums[i]);
//							else ans += ( - nums[i]);
//						}
//					}
//					else {
//						int k = 0;	//否则就只能让最大的负数存在，但注意只能让一个最大的负数存在
//						for (int i = 0; i < nums.size(); i++) {
//							if (max_num == nums[i]) {
//								if (!k) {
//									ans += nums[i];
//									k = 1;
//								}
//								else ans += abs(nums[i]);
//							}
//							else ans += abs(nums[i]);
//						}
//					}
//				}
//			}
//		}
//	}
//	else {
//		if (index) { //如果存在0，没有正数变成负数
//			for (int i = 0; i < nums.size(); i++) {
//				ans += nums[i];
//			}
//		}
//		else {		//如果不存在0
//			if (k % 2 == 0) {//如果k的次数正好为偶数，同样没有正数变成负数
//				for (int i = 0; i < nums.size(); i++) {
//					ans += nums[i];
//				}
//			}
//			else {		//如果k的次数为奇数，那么最小的正数就要变为负数
//				for (int i = 0; i < nums.size(); i++) {
//					if (i == 0) ans += (-nums[i]);
//					else ans += nums[i];
//				}
//			}
//		}
//	}
//	return ans;
//}

//简写版本
int largestSumAfterKNegations(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] < 0 && k) {
			nums[i] = -nums[i];
			--k;
		}
		sum += nums[i];
	}
	if (k == 0) return sum;
	else {
		if (k % 2 == 0) return sum;
		else {
			sort(nums.begin(), nums.end());
			return sum - 2 * nums[0];
		}
	}
}

int main() {
	vector<int> nums = { 8,-7,-3,-9,1,9,-6,-9,3 };
	int k = 8;
	cout << largestSumAfterKNegations(nums, k) << endl;
	return 0;
}