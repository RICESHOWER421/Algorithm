#include <iostream>
#include <cmath>
using namespace std;

//¼ÇÒä»¯ËÑË÷
class Solution {
public:
    int memo[1001];
    int twoEggDrop(int n) {
        if (n == 0) {
            return 0;
        }
        int& res = memo[n];
        if (res) {
            return res;
        }

        res = INT_MAX;
        for (int j = 1; j <= n; j++) {
            res = min(res, max(j, twoEggDrop(n - j) + 1));
        }
        return res;
    }
};

int main() {

	return 0;
}