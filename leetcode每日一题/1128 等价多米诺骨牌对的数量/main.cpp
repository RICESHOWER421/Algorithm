#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> hash_map;
        for (auto& x : dominoes) {
            pair<int, int> ret = { x[0], x[1] };
            if (x[0] > x[1]) {
                swap(ret.first, ret.second);
            }
            hash_map[ret]++;
        }

        int ans = 0;
        auto it = hash_map.begin();
        while (it != hash_map.end()) {
            int num = it->second;
            ans += num * (num - 1) / 2;
            ++it;
        }
        return ans;
    }
};

int main() {

	return 0;
}