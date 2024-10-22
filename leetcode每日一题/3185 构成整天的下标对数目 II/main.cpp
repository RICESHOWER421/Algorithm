#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        vector<int> hash_map(25);
        hash_map[hours[0] % 24]++;
        for (int i = 1; i < (int)hours.size(); i++) {
            if (hash_map[24 - (hours[i] % 24)]) {
                ans += hash_map[24 - (hours[i] % 24)];
            }
            else if (hours[i] % 24 == 0 && hash_map[0]) {
                ans += hash_map[0];
            }
            hash_map[hours[i] % 24]++;
        }
        return ans;
    }
};

int main() {

    return 0;
}