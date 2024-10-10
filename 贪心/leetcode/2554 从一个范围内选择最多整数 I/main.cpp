#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        if (maxSum <= 2) return 0;

        vector<int> hash_map(10001);
        for (auto& x : banned) hash_map[x] = 1;

        int ans = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            if (hash_map[i]) continue;
            else {
                sum += i;
                if (sum > maxSum) break;
                ++ans;
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}