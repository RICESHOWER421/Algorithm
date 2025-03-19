#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> hash_map(201);
        for (auto& x : nums) {
            hash_map[x]++;
        }

        vector<vector<int>> ans;
        while (true) {
            vector<int> tmp;
            for (int i = 1; i <= nums.size(); i++) {
                if (hash_map[i]) {
                    tmp.push_back(i);
                    --hash_map[i];
                }
            }

            if (tmp.empty()) {
                break;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main() {

	return 0;
}