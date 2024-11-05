#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        if (currentEnergy < enemyEnergies[0]) {
            return 0;
        }
        long long ans = 0;
        int index = enemyEnergies.size() - 1;
        while (index >= 0) {
            ans += currentEnergy / enemyEnergies[0];
            currentEnergy %= enemyEnergies[0];
            currentEnergy += enemyEnergies[index--];
        }
        return ans;
    }
};

int main() {

    return 0;
}