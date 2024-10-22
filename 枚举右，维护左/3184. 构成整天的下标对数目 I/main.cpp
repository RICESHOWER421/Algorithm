#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        vector<int> hash_map(24);
        int ans = 0;
        for (auto& x : hours) {
            if (x % 24 == 0) ans += hash_map[0];
            else ans += hash_map[24 - (x % 24)];
            hash_map[x % 24]++;
        }
        return ans;
    }
};

int main() {

	return 0;
}