#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//��һ�ַ�����ֱ������ʱ�临�Ӷ�O(NlogN)
//vector<int> sortedSquares(vector<int>& nums) {
//    vector<int> ret;
//    for (auto& x : nums) ret.push_back(x * x);
//    sort(ret.begin(), ret.end());
//    return ret;
//}

//�ڶ��ַ�����˫ָ�룬ʱ�临�Ӷ�O(N)
vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ret;
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		if (abs(nums[left]) < abs(nums[right])) {
			ret.push_back(nums[right] * nums[right]);
			--right;
		}
		else {
			ret.push_back(nums[left] * nums[left]);
			++left;
		}
	}

	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {

	return 0;
}