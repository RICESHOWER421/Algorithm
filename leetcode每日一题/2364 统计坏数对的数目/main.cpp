#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    long long countBadPairs(vector<int>& nums) {
        ll ans = 0;
        int n = nums.size();
        map<ll, ll> hash_map;
        for (int i = 0; i < n; i++) {
            hash_map[nums[i] - i]++;
        }

        int tmp = n;
        for (int i = 0; i < n; i++) {
            ans += (tmp - hash_map[nums[i] - i]);
            hash_map[nums[i] - i]--;
            --tmp;
        }
        return ans;
    }
};

int main() {

	return 0;
}