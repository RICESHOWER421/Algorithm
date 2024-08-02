#include <iostream>
#include <vector>
#include <set>
using namespace std;


//方法一：质数筛（埃氏筛）
//int vis[1000000];
//int prime[1000000];
//
//void Eratosthenes_sieve(int n)
//{
//	memset(vis, 0, sizeof(int) * 1000000);
//	vis[0] = vis[1] = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		if (vis[i] == 0)
//		{
//			prime[i] = i;
//			for (int j = 2; i * j <= n; j++)
//			{
//				vis[i * j] = 1;
//			}
//		}
//	}
//}
//
//
//int maximumPrimeDifference(vector<int>& nums) {
//	Eratosthenes_sieve(3e5 + 1);
//	vector<int> arr;
//	for (int i = 0; i < nums.size(); i++) 
//		if (prime[nums[i]]) arr.push_back(i);
//	return arr[arr.size() - 1] - arr[0];
//}

//方法二：打表
int maximumPrimeDifference(vector<int>& nums) {
	set<int> arr = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };

	vector<int> ret;
	for (int i = 0; i < nums.size(); i++) 
		if (arr.count(nums[i])) ret.push_back(i);
	return ret[ret.size() - 1] - ret[0];
}

int main() {

	return 0;
}