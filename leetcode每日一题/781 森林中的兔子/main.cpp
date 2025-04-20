#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> hash_map(1001);
        for (auto& x : answers) {
            hash_map[x]++;
        }

        int ans = 0;
        for (int i = 0; i <= 1000; i++) {
            int ret = hash_map[i] / (i + 1) + (hash_map[i] % (i + 1) != 0);
            ans += ret * (i + 1);
        }
        return ans;
    }
};

int main() {

	return 0;
}