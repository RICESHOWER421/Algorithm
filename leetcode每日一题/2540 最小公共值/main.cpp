#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, r = 0, n = nums1.size(), m = nums2.size();
        while (l < n && r < m) {
            if (nums1[l] < nums2[r]) ++l;
            else if (nums1[l] > nums2[r]) ++r;
            else return nums1[l];
        }
        return -1;
    }
};

int main() {

	return 0;
}