#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long ans = 0;
        int max_num = 0;
        for (auto& x : transactions) {
            ans += max(x[0] - x[1], 0);
            max_num = max(max_num, min(x[0], x[1]));
        }
        return ans + max_num;
    }
};

int main() {

    return 0;
}