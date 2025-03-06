#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    using ll = long long;
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        ll ret_1 = 0, ret_2 = 0;
        ll ret_3 = energyDrinkA[0], ret_4 = energyDrinkB[0];
  
        for (int i = 2; i <= n; i++) {
            ll temp_1 = ret_3, temp_2 = ret_4;
            ret_3 = max(ret_3, ret_2) + energyDrinkA[i - 1];
            ret_4 = max(ret_4, ret_1) + energyDrinkB[i - 1];

            ret_1 = temp_1;
            ret_2 = temp_2;
        }
        return max(ret_3, ret_4);
    }
};

int main() {
    vector<int> ret1 = { 4,1,1 };
    vector<int> ret2 = { 1,1,3 };
    cout << Solution().maxEnergyBoost(ret1, ret2) << "\n";
	return 0;
}