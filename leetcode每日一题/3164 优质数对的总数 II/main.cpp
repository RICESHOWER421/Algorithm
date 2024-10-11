#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<int, int> hash_map;
        for (auto& x : nums1) {
            if (x % k) continue;
            x /= k;
            
            int num = sqrt(x);
            for (int i = 1; i <= num; i++) {
                if (x % i == 0) {
                    hash_map[i]++;
                    if (i != x / i) hash_map[x / i]++;
                }
            }
        }

        long long ans = 0;
        for (auto& x : nums2) {
            if (hash_map.count(x)) ans += hash_map[x];
        }
        return ans;
    }
};

int main() {
    vector<int> nums1 = { 1,2,4,12};
    vector<int> nums2 = { 2,4 };
    int k = 3;
    cout << Solution().numberOfPairs(nums1, nums2, k) << endl;
	return 0;
}