#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, cur = -1;
        for (int i = 0; i < 32; i++) {
            if (n % 2) {
                if (cur == -1) cur = i;
                else {
                    ans = max(ans, i - cur);
                    cur = i;
                }
            }
            n /= 2;
        }
        return ans;
    }
};

int main() {

	return 0;
}