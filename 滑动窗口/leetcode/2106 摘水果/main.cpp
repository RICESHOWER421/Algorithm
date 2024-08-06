#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

//最难顶的滑动窗口，如果使用滑动窗口的话细节很多，而且非常复杂。
//这里使用两个for循环是因为一个是从左往右摘，一个从右往左摘，两种情况合在一起取最大值。总之写的非常冗杂。
//而且还用了哈希存储每个位置的水果数以便每次移动窗口边界时都能知道这个位置是否存在水果，导致时间复杂度有点大
//但还是写出来了，只能说能过就行:)
int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
	int ans = 0;

	map<int, int> hash_map;
	for (int i = 0; i < fruits.size(); i++) hash_map[fruits[i][0]] = fruits[i][1];

	int left = startPos - k, right = startPos;
	int sum = 0;
	for (int i = 0; i < fruits.size(); i++) {
		if (fruits[i][0] < left) continue;
		else if (fruits[i][0] >= left && fruits[i][0] <= right) sum += fruits[i][1];
		else {
			int temp = fruits[i][0] - startPos;
			if (temp > k / 2) break;
			else {
				int num = fruits[i][0] - right;
				right = fruits[i][0];
				sum += fruits[i][1];
				while (num--) {
					if (hash_map.count(left)) sum -= hash_map[left];
					++left;
					if (hash_map.count(left)) sum -= hash_map[left];
					++left;
				}
			}
		}
		ans = max(sum, ans);
	}

	left = startPos, right = startPos + k;
	sum = 0;
	for (int i = fruits.size() - 1; i >= 0; i--) {
		if (fruits[i][0] > right) continue;
		if (fruits[i][0] <= right && fruits[i][0] >= left) sum += fruits[i][1];
		else {
			int temp = left - startPos;
			if (temp > k / 2) break;
			else {
				int num = left - fruits[i][0];
				left = fruits[i][0];
				sum += fruits[i][1];
				while (num--) {
					if (hash_map.count(right)) sum -= hash_map[right];
					--right;
					if (hash_map.count(right)) sum -= hash_map[right];
					--right;
				}
			}
		}
		ans = max(ans, sum);
	}
	return ans;
}

int main() {
	vector<vector<int>> fruits = { {0,3},{6,4},{8,5} };
	int startPos = 3, k = 2;
	cout << maxTotalFruits(fruits, startPos, k) << endl;
	return 0;
}