#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int ret = 0;
        for (int i = 0; i < (int)cost.size(); i++) {
            if (i % 3 != 2) ret += cost[i];
        }
        return ret;
    }
};

int main() {

	return 0;
}