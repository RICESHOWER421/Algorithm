#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> hash_map(101);
        for (auto& x : nums) {
            hash_map[x]++;
            if (hash_map[x] > 2) {
                return false;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}