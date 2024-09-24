#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		map<int, int> hash_map;
		for (auto& x1 : nums1) {
			for (auto& x2 : nums2) {
				hash_map[x1 + x2]++;
			}
		}

		int ans = 0;
		for (auto& x1 : nums3) {
			for (auto& x2 : nums4) {
				if (hash_map.count(-x1 - x2)) {
					ans += hash_map[-x1 - x2];
				}
			}
		}
		return ans;
	}
};
int main() {

	return 0;
}