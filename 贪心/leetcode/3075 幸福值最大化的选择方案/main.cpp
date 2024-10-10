#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long ans = 0;
        int ret = 0;
        for (auto& x : happiness) {
            ans += (x - ret > 0 ? x - ret : 0);
            ++ret;
            if (ret == k) break;
        }
        return ans;
    }
};

int main() {

	return 0;
}