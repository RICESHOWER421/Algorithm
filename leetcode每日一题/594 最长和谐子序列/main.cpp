#include <bits/stdc++.h>
using namespace std;

//class Solution {
//public:
//    int findLHS(vector<int>& nums) {
//        int ans = 0;
//        unordered_map<int, int> hash_map;
//        for (auto& x : nums) {
//            hash_map[x]++;
//            if (hash_map.count(x + 1)) ans = max(ans, hash_map[x] + hash_map[x + 1]);
//            if (hash_map.count(x - 1)) ans = max(ans, hash_map[x] + hash_map[x - 1]);
//        }
//        return ans;
//    }
//};

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> hash_map;
        for (auto& x : nums) {
            hash_map[x]++;
        }

        for (auto& [a, b] : hash_map) {
            if (hash_map.count(a - 1)) ans = max(ans, hash_map[a] + hash_map[a - 1]);
        }
        return ans;
    }
};

int main() {

	return 0;
}