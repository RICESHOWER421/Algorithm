#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    long long beautifulSubarrays(vector<int>& nums) {
        ll ans = 0, ret = 0;
        map<int, int> hash_map;
        hash_map[0] = 1;
        for (auto& x : nums) {
            ret ^= x;
            ans += hash_map[ret]++;
        }
        return ans;
    }
};

int main() {

	return 0;
}