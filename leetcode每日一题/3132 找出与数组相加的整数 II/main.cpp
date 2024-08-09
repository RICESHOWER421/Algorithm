#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//首先我们对两个数组进行排序
//因为nums1删除两个元素之后，剩下的值和nums2的值相减差值是一样的，所以我们可以知道前三个值中一定有一个值是删不掉需要保留的
//所以我们就可以用nums1前三个数和nums2的第一个值的差值依次枚举，寻找差值一样的子序列就可以了
//唯一的细节就是，遍历是从第三个数开始遍历的，因为要返回的是最大差值，所以越往右边的数差值就会越大
int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	for (int i = 2; i >= 0; i--) {
		int num = nums2[0] - nums1[i];
		int index = 0;
		for (int j = i; j < nums1.size(); j++) {
			if (nums1[j] + num == nums2[index]) ++index;
			if (index == nums2.size()) return num;
		}
	}
	return 0;
}

int main() {
	vector<int> nums1 = { 3,5,5,3};
	vector<int> nums2 = { 7,7 };
	cout << minimumAddedInteger(nums1, nums2) << endl;
	return 0;
}