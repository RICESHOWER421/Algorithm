#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//排序找最小值
int addedInteger(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    return nums2[0] - nums1[0];
}
//找最小值
int addedInteger(vector<int>& nums1, vector<int>& nums2) {
    int min_1 = INT_MAX, min_2 = INT_MAX;
    for (int i = 0; i < nums1.size(); i++) {
        min_1 = min(min_1, nums1[i]);
        min_2 = min(min_2, nums2[i]);
    }
    return min_2 - min_1;
}

int main() {

	return 0;
}