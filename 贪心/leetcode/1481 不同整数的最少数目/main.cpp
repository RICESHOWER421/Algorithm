#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> hash_map;
        vector<int> nums;
        for (auto& x : arr) {
            if (!hash_map.count(x)) nums.push_back(x);
            hash_map[x]++;
        }

        sort(nums.begin(), nums.end(), [&](const int a, const int b) {
            return hash_map[a] < hash_map[b];
            });

        int index = 0;
        int ans = 0;
        while (k) {
            if (k >= hash_map[nums[index]]) {
                k -= hash_map[nums[index++]];
                ++ans;
            }
            else break;
        }
        return (int)nums.size() - ans;
    }
};

int main() {

	return 0;
}