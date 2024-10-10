#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> hash_map(100001);
        vector<int> nums;
        for (auto& x : arr) {
            if (!hash_map[x]) nums.push_back(x);
            hash_map[x]++;
        }

        sort(nums.begin(), nums.end(), [&](const int a, const int b) {
            return hash_map[a] > hash_map[b];
        });

        int ans = 0;
        int ret = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            ret += hash_map[nums[i]];
            ++ans;
            if (ret >= (int)arr.size() / 2) break;
        }
        return ans;
    }
};

int main() {

	return 0;
}