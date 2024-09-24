#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int> hash_map;
        int ret = INT_MAX;
        int left = 0;
        for (int i = 0; i < (int)cards.size(); i++) {
            if (left != i && hash_map.count(cards[i]) && hash_map[cards[i]] != -1) {
                ret = min(ret, i - hash_map[cards[i]] + 1);
                while (hash_map[cards[i]] != -1) {
                    hash_map[cards[left++]] = -1;
                }
            }
            hash_map[cards[i]] = i;
        }
        return (ret == INT_MAX ? -1 : ret);
    }
};

int main() {

    return 0;
}