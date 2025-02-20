#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        for (int i = 0; i < 32; i++) {
            if (n % 2) {
                ans[i % 2]++;
            }
            n >>= 1;
        }
        return ans;
    }
};

int main() {

	return 0;
}